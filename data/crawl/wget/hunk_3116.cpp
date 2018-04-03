 }
 
 void
-ws_help (const char *name)
-{
-  char *mypath = ws_mypath ();
-
-  if (mypath)
-    {
-      struct stat sbuf;
-      char *buf = (char *)alloca (strlen (mypath) + strlen (name) + 4 + 1);
-      sprintf (buf, "%s%s.HLP", mypath, name);
-      if (stat (buf, &sbuf) == 0) 
-	{
-          printf (_("Starting WinHelp %s\n"), buf);
-          WinHelp (NULL, buf, HELP_INDEX, 0);
-        }
-      else
-        {
-          printf ("%s: %s\n", buf, strerror (errno));
-        }
-    }
-}
-
-void
 ws_startup (void)
 {
   WORD requested;
