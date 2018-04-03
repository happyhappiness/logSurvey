         }
     }
 
-    shcmd = debug ? HELPERSCRIPT : HELPERSCRIPT " > /dev/null 2>&1";
+    shcmd = debug_enabled ? HELPERSCRIPT : HELPERSCRIPT " > /dev/null 2>&1";
 
     /* pass to helper script */
     if (putenv((char *)"SAMBAPREFIX=" SAMBAPREFIX) != 0)
         return 1;
 
-    while (1) {
-        if (fgets(buf, BUFSIZE, stdin) == NULL)
-            break;
+    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
 
         if ((s = strchr(buf, '\n')) == NULL)
             continue;
         *s = '\0';
 
         if ((s = strchr(buf, ' ')) == NULL) {
-            (void) printf("ERR\n");
+            SEND_ERR("");
             continue;
         }
         *s = '\0';
