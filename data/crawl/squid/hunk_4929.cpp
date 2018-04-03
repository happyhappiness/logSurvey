+/*
+ * DEBUG: section 93  ICAP (RFC 3507) Client
+ */
+
+#include "squid.h"
+#include "comm.h"
+#include "HttpReply.h"
+#include "ICAPXaction.h"
+#include "ICAPClient.h"
+#include "TextException.h"
+
+/* comm module handlers (wrappers around corresponding ICAPXaction methods */
+
+// TODO: Teach comm module to call object methods directly
+
+//CBDATA_CLASS_INIT(ICAPXaction);
+
+static
+ICAPXaction &ICAPXaction_fromData(void *data)
+{
+    ICAPXaction *x = static_cast<ICAPXaction*>(data);
+    assert(x);
+    return *x;
+}
+
+static
+void ICAPXaction_noteCommTimedout(int, void *data)
+{
+    ICAPXaction_fromData(data).noteCommTimedout();
+}
+
+static
+void ICAPXaction_noteCommClosed(int, void *data)
+{
+    ICAPXaction_fromData(data).noteCommClosed();
+}
+
+static
+void ICAPXaction_noteCommConnected(int, comm_err_t status, int xerrno, void *data)
+{
+    ICAPXaction_fromData(data).noteCommConnected(status);
+}
+
+static
+void ICAPXaction_noteCommWrote(int, char *, size_t size, comm_err_t status, void *data)
+{
+    ICAPXaction_fromData(data).noteCommWrote(status, size);
+}
+
+static
+void ICAPXaction_noteCommRead(int, char *, size_t size, comm_err_t status, int xerrno, void *data)
+{
+    ICAPXaction_fromData(data).noteCommRead(status, size);
+}
+
+ICAPXaction::ICAPXaction(const char *aTypeName):
+        connection(-1),
+        commBuf(NULL), commBufSize(0),
+        commEof(false),
+        connector(NULL), reader(NULL), writer(NULL), closer(NULL),
+        typeName(aTypeName),
+        theService(NULL),
+        inCall(NULL)
+{
+    readBuf.init(SQUID_TCP_SO_RCVBUF, SQUID_TCP_SO_RCVBUF);
+    commBuf = (char*)memAllocBuf(SQUID_TCP_SO_RCVBUF, &commBufSize);
+    // make sure maximum readBuf space does not exceed commBuf size
+    Must(static_cast<size_t>(readBuf.potentialSpaceSize()) <= commBufSize);
+}
+
+ICAPXaction::~ICAPXaction()
+{
+    doStop();
+    readBuf.clean();
+    memFreeBuf(commBufSize, commBuf);
+}
+
+// TODO: obey service-specific, OPTIONS-reported connection limit
+void ICAPXaction::openConnection()
+{
+    const ICAPServiceRep &s = service();
+    // TODO: check whether NULL domain is appropriate here
+    connection = pconnPop(s.host.buf(), s.port, NULL);
+
+    if (connection < 0) {
+        connection = comm_open(SOCK_STREAM, 0, getOutgoingAddr(NULL), 0,
+                               COMM_NONBLOCKING, s.uri.buf());
+
+        if (connection < 0)
+            throw TexcHere("cannot connect to ICAP service " /* + uri */);
+    }
+
+    debugs(93,3, typeName << " opens connection to " << s.host.buf() << ":" << s.port);
+
+    commSetTimeout(connection, Config.Timeout.connect,
+                   &ICAPXaction_noteCommTimedout, this);
+
+    closer = &ICAPXaction_noteCommClosed;
+    comm_add_close_handler(connection, closer, this);
+
+    connector = &ICAPXaction_noteCommConnected;
+    commConnectStart(connection, s.host.buf(), s.port, connector, this);
+}
+
+void ICAPXaction::closeConnection()
+{
+    if (connection >= 0) {
+        commSetTimeout(connection, -1, NULL, NULL);
+
+        if (closer) {
+            comm_remove_close_handler(connection, closer, this);
+            closer = NULL;
+        }
+
+        cancelRead();
+
+        comm_close(connection);
+
+        connector = NULL;
+        connection = -1;
+    }
+}
+
+// connection with the ICAP service established
+void ICAPXaction::noteCommConnected(comm_err_t commStatus)
+{
+    ICAPXaction_Enter(noteCommConnected);
+
+    Must(connector);
+    connector = NULL;
+    Must(commStatus == COMM_OK);
+
+    handleCommConnected();
+
+    ICAPXaction_Exit();
+}
+
+void ICAPXaction::scheduleWrite(MemBuf &buf)
+{
+    // comm module will free the buffer
+    writer = &ICAPXaction_noteCommWrote;
+    comm_old_write_mbuf(connection, &buf, writer, this);
+}
+
+void ICAPXaction::noteCommWrote(comm_err_t commStatus, size_t size)
+{
+    ICAPXaction_Enter(noteCommWrote);
+
+    Must(writer);
+    writer = NULL;
+
+    Must(commStatus == COMM_OK);
+
+    handleCommWrote(size);
+
+    ICAPXaction_Exit();
+}
+
+// communication timeout with the ICAP service
+void ICAPXaction::noteCommTimedout()
+{
+    ICAPXaction_Enter(noteCommTimedout);
+
+    handleCommTimedout();
+
+    ICAPXaction_Exit();
+}
+
+void ICAPXaction::handleCommTimedout()
+{
+    mustStop("connection with ICAP service timed out");
+}
+
+// unexpected connection close while talking to the ICAP service
+void ICAPXaction::noteCommClosed()
+{
+    closer = NULL;
+    ICAPXaction_Enter(noteCommClosed);
+
+    handleCommClosed();
+
+    ICAPXaction_Exit();
+}
+
+void ICAPXaction::handleCommClosed()
+{
+    mustStop("ICAP service connection externally closed");
+}
+
+bool ICAPXaction::done() const
+{
+    if (stopReason != NULL) // mustStop() has been called
+        return true;
+
+    return doneAll();
+}
+
+bool ICAPXaction::doneAll() const
+{
+    return !connector && !reader && !writer;
+}
+
+void ICAPXaction::scheduleRead()
+{
+    Must(connection >= 0);
+    Must(!reader);
+    Must(readBuf.hasSpace());
+
+    reader = &ICAPXaction_noteCommRead;
+    /*
+     * See comments in ICAPXaction.h about why we use commBuf
+     * here instead of reading directly into readBuf.buf.
+     */
+
+    comm_read(connection, commBuf, readBuf.spaceSize(), reader, this);
+}
+
+// comm module read a portion of the ICAP response for us
+void ICAPXaction::noteCommRead(comm_err_t commStatus, size_t sz)
+{
+    ICAPXaction_Enter(noteCommRead);
+
+    Must(reader);
+    reader = NULL;
+
+    Must(commStatus == COMM_OK);
+    Must(sz >= 0);
+
+    debugs(93, 5, "read " << sz << " bytes");
+
+    /*
+     * See comments in ICAPXaction.h about why we use commBuf
+     * here instead of reading directly into readBuf.buf.
+     */
+
+    if (sz > 0)
+        readBuf.append(commBuf, sz);
+    else
+        commEof = true;
+
+    handleCommRead(sz);
+
+    ICAPXaction_Exit();
+}
+
+void ICAPXaction::cancelRead()
+{
+    if (reader) {
+        // check callback presence because comm module removes
+        // fdc_table[].read.callback after the actual I/O but
+        // before we get the callback via a queued event.
+        // These checks try to mimic the comm_read_cancel() assertions.
+
+        if (comm_has_pending_read(connection) &&
+                !comm_has_pending_read_callback(connection))
+            comm_read_cancel(connection, reader, this);
+
+        reader = NULL;
+    }
+}
+
+bool ICAPXaction::parseHttpMsg(HttpMsg *msg)
+{
+    debugs(93, 5, "have " << readBuf.contentSize() << " head bytes to parse");
+
+    http_status error = HTTP_STATUS_NONE;
+    const bool parsed = msg->parse(&readBuf, commEof, &error);
+    Must(parsed || !error); // success or need more data
+
+    if (!parsed) {	// need more data
+        Must(mayReadMore());
+        msg->reset();
+        return false;
+    }
+
+    readBuf.consume(msg->hdr_sz);
+    return true;
+}
+
+bool ICAPXaction::mayReadMore() const
+{
+    return !doneReading() && // will read more data
+           readBuf.hasSpace();  // have space for more data
+}
+
+bool ICAPXaction::doneReading() const
+{
+    return commEof;
+}
+
+void ICAPXaction::mustStop(const char *aReason)
+{
+    Must(inCall); // otherwise nobody will call doStop()
+    Must(!stopReason);
+    Must(aReason);
+    stopReason = aReason;
+    debugs(93, 5, typeName << " will stop, reason: " << stopReason);
+}
+
+// internal cleanup
+void ICAPXaction::doStop()
+{
+    debugs(93, 5, typeName << "::doStop " << status());
+
+    closeConnection(); // TODO: pconn support: close iff bad connection
+}
+
+void ICAPXaction::service(ICAPServiceRep::Pointer &aService)
+{
+    Must(!theService);
+    Must(aService != NULL);
+    theService = aService;
+}
+
+ICAPServiceRep &ICAPXaction::service()
+{
+    Must(theService != NULL);
+    return *theService;
+}
+
+bool ICAPXaction::callStart(const char *method)
+{
+    debugs(93, 5, typeName << "::" << method << " called " << status());
+
+    if (inCall) {
+        // this may happen when we have bugs or when arguably buggy
+        // comm interface calls us while we are closing the connection
+        debugs(93, 5, typeName << "::" << inCall << " is in progress; " <<
+               typeName << "::" << method << " cancels reentry.");
+        return false;
+    }
+
+    inCall = method;
+    return true;
+}
+
+void ICAPXaction::callException(const TextException &e)
+{
+    debugs(93, 4, typeName << "::" << inCall << " caught an exception: " <<
+           e.message << ' ' << status());
+
+    if (!done())
+        mustStop("exception");
+}
+
+void ICAPXaction::callEnd()
+{
+    if (done()) {
+        debugs(93, 5, "ICAPXaction::" << inCall << " ends xaction " <<
+               status());
+        doStop(); // may delete us
+        return;
+    }
+
+    debugs(93, 6, typeName << "::" << inCall << " ended " << status());
+    inCall = NULL;
+}
+
+// returns a temporary string depicting transaction status, for debugging
+const char *ICAPXaction::status() const
+{
+    static MemBuf buf;
+    buf.reset();
+
+    buf.append("[", 1);
+
+    fillPendingStatus(buf);
+    buf.append("/", 1);
+    fillDoneStatus(buf);
+
+    buf.append("]", 1);
+
+    buf.terminate();
+
+    return buf.content();
+}
+
+void ICAPXaction::fillPendingStatus(MemBuf &buf) const
+{
+    if (connection >= 0) {
+        buf.Printf("Comm(%d", connection);
+
+        if (writer)
+            buf.append("w", 1);
+
+        if (reader)
+            buf.append("r", 1);
+
+        buf.append(")", 1);
+    }
+}
+
+void ICAPXaction::fillDoneStatus(MemBuf &buf) const
+{
+    if (connection >= 0 && commEof)
+        buf.Printf("Comm(%d)", connection);
+
+    if (stopReason != NULL)
+        buf.Printf("Stopped");
+}
