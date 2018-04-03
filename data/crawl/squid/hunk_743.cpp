 
     static MemBuf buf;
     buf.reset();
-    buf.Printf(" FD %d, %s",conn->fd, ipbuf);
+    buf.appendf(" FD %d, %s",conn->fd, ipbuf);
 
     const char *jobStatus = AsyncJob::status();
     buf.append(jobStatus, strlen(jobStatus));
