     return -1;
 
 #ifdef SO_REUSEADDR
-  setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, setopt_ptr, setopt_size);
+  if (setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, setopt_ptr, setopt_size))
+    logprintf (LOG_NOTQUIET, _("setsockopt SO_REUSEADDR failed: %s\n"),
+               strerror (errno));
 #endif
 
   xzero (ss);
