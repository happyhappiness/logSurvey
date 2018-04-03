 ftp_request (const char *command, const char *value)
 {
   char *res = (char *)xmalloc (strlen (command)
-			       + (value ? (1 + strlen (value)) : 0)
-			       + 2 + 1);
+                               + (value ? (1 + strlen (value)) : 0)
+                               + 2 + 1);
   sprintf (res, "%s%s%s\r\n", command, value ? " " : "", value ? value : "");
   if (opt.server_response)
     {
       /* Hack: don't print out password.  */
       if (strncmp (res, "PASS", 4) != 0)
-	logprintf (LOG_ALWAYS, "--> %s\n", res);
+        logprintf (LOG_ALWAYS, "--> %s\n", res);
       else
-	logputs (LOG_ALWAYS, "--> PASS Turtle Power!\n");
+        logputs (LOG_ALWAYS, "--> PASS Turtle Power!\n");
     }
   else
     DEBUGP (("\n--> %s\n", res));
