     setbuf(stdin, NULL);
 
     if (!server) {
-        fprintf(stderr, "Error: No server name\n");
+        std::cerr << "ERROR: GSSAPI: No server name" << std::endl;
         return (char *)"ERROR";
     }
     service.value = xmalloc(strlen("HTTP") + strlen(server) + 2);