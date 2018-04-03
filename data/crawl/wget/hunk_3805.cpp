 static int
 cmd_address (const char *com, const char *val, void *closure)
 {
-    struct sockaddr_in *sin;
-    
-    sin = (struct sockaddr_in *) malloc(sizeof *sin);
-    if (sin == NULL)
-    {
-	fprintf (stderr, _("%s: Out of memory.\n"), exec_name);
-	return 0;
-    }
-    
-    if (!store_hostaddress ((unsigned char *)&sin->sin_addr, val))
+  struct sockaddr_in sin;
+
+  if (!store_hostaddress ((unsigned char *)&sin.sin_addr, val))
     {
-	fprintf (stderr, _("%s: %s: Cannot convert `%s' to an IP address.\n"),
-		 exec_name, com, val);
-	return 0;
+      fprintf (stderr, _("%s: %s: Cannot convert `%s' to an IP address.\n"),
+	       exec_name, com, val);
+      return 0;
     }
-    
-    sin->sin_family = AF_INET;
-    sin->sin_port = 0;
-    
-    * (struct sockaddr_in **) closure = sin;
-    
-    return 1;
+
+  sin.sin_family = AF_INET;
+  sin.sin_port = 0;
+
+  memcpy (closure, &sin, sizeof (sin));
+
+  return 1;
 }
 
 /* Store the boolean value from VAL to CLOSURE.  COM is ignored,
