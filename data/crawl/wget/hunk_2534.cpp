 
   /* If no transmission was required, then everything is OK.  */
   if (!pasv_mode_open)  /* we are not using pasive mode so we need
-			      to accept */
+                              to accept */
     {
       /* Wait for the server to connect to the address we're waiting
-	 at.  */
+         at.  */
       dtsock = accept_connection (local_sock);
       if (dtsock < 0)
-	{
-	  logprintf (LOG_NOTQUIET, "accept: %s\n", strerror (errno));
-	  return err;
-	}
+        {
+          logprintf (LOG_NOTQUIET, "accept: %s\n", strerror (errno));
+          return err;
+        }
     }
 
   /* Open the file -- if output_stream is set, use it instead.  */
