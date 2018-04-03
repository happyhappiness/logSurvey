      print it out.  */
   if (opt.server_response && (con->cmd & DO_LIST))
     {
-      mkalldirs (u->local);
-      fp = fopen (u->local, "r");
+      mkalldirs (con->target);
+      fp = fopen (con->target, "r");
       if (!fp)
-	logprintf (LOG_ALWAYS, "%s: %s\n", u->local, strerror (errno));
+	logprintf (LOG_ALWAYS, "%s: %s\n", con->target, strerror (errno));
       else
 	{
 	  char *line;
