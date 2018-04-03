 Snmp::Inquirer::noteCommClosed(const CommCloseCbParams& params)
 {
     debugs(49, 5, HERE);
-    Must(fd < 0 || fd == params.fd);
-    fd = -1;
+    Must(!Comm::IsConnOpen(conn) || conn->fd == params.conn->fd);
+    conn = NULL;
     mustStop("commClosed");
 }
 
