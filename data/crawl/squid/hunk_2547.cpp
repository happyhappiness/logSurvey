 {
     debugs(5,5, HERE);
     unsubscribe("swanSong");
-    fd = -1;
+    conn = NULL;
     AcceptLimiter::Instance().removeDead(this);
     AsyncJob::swanSong();
 }
 
 const char *
 Comm::TcpAcceptor::status() const
 {
+    if (conn == NULL)
+        return "[nil connection]";
+
     static char ipbuf[MAX_IPSTRLEN] = {'\0'};
     if (ipbuf[0] == '\0')
-        local_addr.ToHostname(ipbuf, MAX_IPSTRLEN);
+        conn->local.ToHostname(ipbuf, MAX_IPSTRLEN);
 
     static MemBuf buf;
     buf.reset();
-    buf.Printf(" FD %d, %s",fd, ipbuf);
+    buf.Printf(" FD %d, %s",conn->fd, ipbuf);
 
     const char *jobStatus = AsyncJob::status();
     buf.append(jobStatus, strlen(jobStatus));
