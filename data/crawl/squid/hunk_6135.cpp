     return h.id;
 }
 
+/*
+ * rfc1035BuildPTRQuery()
+ * 
+ * Builds a message buffer with a QUESTION to lookup PTR records
+ * for an address.  Caller must allocate 'buf' which should
+ * probably be at least 512 octets.  The 'szp' initially
+ * specifies the size of the buffer, on return it contains
+ * the size of the message (i.e. how much to write).
+ * Return value is the query ID.
+ */
+unsigned short
+rfc1035BuildPTRQuery(const struct in_addr addr, char *buf, size_t * szp)
+{
+    static rfc1035_header h;
+    off_t offset = 0;
+    size_t sz = *szp;
+    static char rev[32];
+    unsigned int i;
+    memset(&h, '\0', sizeof(h));
+    i = (unsigned int) addr.s_addr;
+    snprintf(rev, 32, "%u.%u.%u.%u.in-addr.arpa",
+	(i >> 24) & 255,
+	(i >> 16) & 255,
+	(i >> 8) & 255,
+	i & 255);
+    printf("rfc1035BuildPTRQuery: {%s}\n", rev);
+    h.id = rfc1035Qid();
+    h.qr = 0;
+    h.rd = 1;
+    h.opcode = 0;		/* QUERY */
+    h.qdcount = (unsigned int) 1;
+    offset += rfc1035HeaderPack(buf + offset, sz - offset, &h);
+    offset += rfc1035QuestionPack(buf + offset,
+	sz - offset,
+	rev,
+	RFC1035_TYPE_PTR,
+	RFC1035_CLASS_IN);
+    assert(offset <= sz);
+    *szp = (size_t) offset;
+    return h.id;
+}
+
 #if DRIVER
+#include <sys/socket.h>
+#include <sys/time.h>
 int
 main(int argc, char *argv[])
 {
-    rfc1035_header h;
     char input[512];
     char buf[512];
     char rbuf[512];
     size_t sz = 512;
     unsigned short sid;
-    off_t offset = 0;
     int s;
     int rl;
     struct sockaddr_in S;
