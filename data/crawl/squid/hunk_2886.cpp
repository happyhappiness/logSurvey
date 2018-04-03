 Mgr::Inquirer::noteCommClosed(const CommCloseCbParams& params)
 {
     debugs(16, 5, HERE);
-    Must(fd < 0 || fd == params.fd);
-    fd = -1;
+    Must(!Comm::IsConnOpen(clientConnection) || clientConnection->fd == params.fd);
+    clientConnection = NULL; // AYJ: Do we actually have to NULL it?
     mustStop("commClosed");
 }
 
