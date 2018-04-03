   Rpc_Stat status;
   int pid;
 
-  /* Find the current directory.  */
-  if (getcwd (cwd, GET_PATH_MAX) == 0)
-    {
-#ifdef	HAVE_GETCWD
-      perror_with_name ("exporting: getcwd: ", "");
-#else
-      error ("exporting: getwd: %s", cwd);
-#endif
-      return 1;
-    }
-
-  /* Normalize the current directory path name to something
-     that should work on all machines exported to.  */
-  if (Customs_NormPath (cwd, GET_PATH_MAX) < 0)
-    {
-      error ("exporting: path normalization failed: %s", cwd);
-      return 1;
-    }
-
   /* Create the return socket.  */
   retsock = Rpc_UdpCreate (True, 0);
   if (retsock < 0)
