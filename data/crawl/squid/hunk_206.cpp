     ll->flush_pending = 0;
 
     int ret = FD_WRITE_METHOD(ll->wfd, b->buf + b->written_len, b->len - b->written_len);
+    int xerrno = errno;
     debugs(50, 3, lf->path << ": write returned " << ret);
     if (ret < 0) {
-        if (ignoreErrno(errno)) {
+        if (ignoreErrno(xerrno)) {
             /* something temporary */
             Comm::SetSelect(ll->wfd, COMM_SELECT_WRITE, logfileHandleWrite, lf, 0);
             ll->flush_pending = 1;
             return;
         }
-        debugs(50, DBG_IMPORTANT,"logfileHandleWrite: " << lf->path << ": error writing (" << xstrerror() << ")");
+        debugs(50, DBG_IMPORTANT,"logfileHandleWrite: " << lf->path << ": error writing (" << xstrerr(xerrno) << ")");
         /* XXX should handle this better */
         fatal("I don't handle this error well!");
     }
