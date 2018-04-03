     if (!handler)
 	fatal_dump("ipcache_nbgethostbyname: NULL handler");
 
-    debug(14, 4, "ipcache_nbgethostbyname: FD %d: Name '%s'.\n", fd, name);
+    debug(14, 4) ("ipcache_nbgethostbyname: FD %d: Name '%s'.\n", fd, name);
     IpcacheStats.requests++;
 
     if (name == NULL || name[0] == '\0') {
-	debug(14, 4, "ipcache_nbgethostbyname: Invalid name!\n");
+	debug(14, 4) ("ipcache_nbgethostbyname: Invalid name!\n");
 	handler(fd, NULL, handlerData);
 	return;
     }
