  */
 void
 comm_write(int fd, const char *buf, int size, IOCB * handler, void *handler_data, FREE * free_func)
+{
+    AsyncCall::Pointer call = commCbCall(5,5, "SomeCommWriteHander",
+        CommIoCbPtrFun(handler, handler_data));
+
+    comm_write(fd, buf, size, call, free_func);
+}
+
+void
+comm_write(int fd, const char *buf, int size, AsyncCall::Pointer &callback, FREE * free_func)
 {
     assert(!fd_table[fd].flags.closing);
 
-    debugs(5, 5, "comm_write: FD " << fd << ": sz " << size << ": hndl " << handler << ": data " << handler_data << ".");
+    debugs(5, 5, "comm_write: FD " << fd << ": sz " << size << ": asynCall " << callback  << ".");
 
     if (commio_has_callback(fd, IOCB_WRITE, COMMIO_FD_WRITECB(fd))) {
         /* This means that the write has been scheduled, but has not
          * triggered yet 
          */
         fatalf ("comm_write: fd %d: pending callback!\n", fd);
     }
-    /* XXX ugly */
-    commio_set_callback(fd, IOCB_WRITE, COMMIO_FD_WRITECB(fd), handler, handler_data, (char *)buf, free_func, size);
+
+    commio_set_callback(fd, IOCB_WRITE, COMMIO_FD_WRITECB(fd),
+        callback, (char *)buf, free_func, size);
     commSetSelect(fd, COMM_SELECT_WRITE, commHandleWrite, COMMIO_FD_WRITECB(fd), 0);
 }
 
+
 /* a wrapper around comm_write to allow for MemBuf to be comm_written in a snap */
 void
 comm_write_mbuf(int fd, MemBuf *mb, IOCB * handler, void *handler_data) {
     comm_write(fd, mb->buf, mb->size, handler, handler_data, mb->freeFunc());
 }
 
+void
+comm_write_mbuf(int fd, MemBuf *mb, AsyncCall::Pointer &callback) {
+    comm_write(fd, mb->buf, mb->size, callback, mb->freeFunc());
+}
+
 
 /*
  * hm, this might be too general-purpose for all the places we'd
