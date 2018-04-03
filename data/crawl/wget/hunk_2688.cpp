       hs->res = 0;
       xfree_null (type);
       if (head_only)
-	/* Pre-1.10 Wget used CLOSE_INVALIDATE here.  Now we trust the
-	   servers not to send body in response to a HEAD request, and
-	   those that do will likely be caught by test_socket_open.
-	   If not, they can be worked around using
-	   `--no-http-keep-alive'.  */
-	CLOSE_FINISH (sock);
+        /* Pre-1.10 Wget used CLOSE_INVALIDATE here.  Now we trust the
+           servers not to send body in response to a HEAD request, and
+           those that do will likely be caught by test_socket_open.
+           If not, they can be worked around using
+           `--no-http-keep-alive'.  */
+        CLOSE_FINISH (sock);
       else if (keep_alive && skip_short_body (sock, contlen))
-	/* Successfully skipped the body; also keep using the socket. */
-	CLOSE_FINISH (sock);
+        /* Successfully skipped the body; also keep using the socket. */
+        CLOSE_FINISH (sock);
       else
-	CLOSE_INVALIDATE (sock);
+        CLOSE_INVALIDATE (sock);
       return RETRFINISHED;
     }
 
   /* Open the local file.  */
   if (!output_stream)
     {
-      mkalldirs (*hs->local_file);
+      mkalldirs (hs->local_file);
       if (opt.backups)
-	rotate_backups (*hs->local_file);
+        rotate_backups (hs->local_file);
       if (hs->restval)
-	fp = fopen (*hs->local_file, "ab");
+        fp = fopen (hs->local_file, "ab");
       else if (ALLOW_CLOBBER)
-	fp = fopen (*hs->local_file, "wb");
+        fp = fopen (hs->local_file, "wb");
       else
-	{
-	  fp = fopen_excl (*hs->local_file, true);
-	  if (!fp && errno == EEXIST)
-	    {
-	      /* We cannot just invent a new name and use it (which is
-		 what functions like unique_create typically do)
-		 because we told the user we'd use this name.
-		 Instead, return and retry the download.  */
-	      logprintf (LOG_NOTQUIET,
-			 _("%s has sprung into existence.\n"),
-			 *hs->local_file);
-	      CLOSE_INVALIDATE (sock);
-	      return FOPEN_EXCL_ERR;
-	    }
-	}
+        {
+          fp = fopen_excl (hs->local_file, true);
+          if (!fp && errno == EEXIST)
+            {
+              /* We cannot just invent a new name and use it (which is
+                 what functions like unique_create typically do)
+                 because we told the user we'd use this name.
+                 Instead, return and retry the download.  */
+              logprintf (LOG_NOTQUIET,
+                         _("%s has sprung into existence.\n"),
+                         hs->local_file);
+              CLOSE_INVALIDATE (sock);
+              return FOPEN_EXCL_ERR;
+            }
+        }
       if (!fp)
-	{
-	  logprintf (LOG_NOTQUIET, "%s: %s\n", *hs->local_file, strerror (errno));
-	  CLOSE_INVALIDATE (sock);
-	  return FOPENERR;
-	}
+        {
+          logprintf (LOG_NOTQUIET, "%s: %s\n", hs->local_file, strerror (errno));
+          CLOSE_INVALIDATE (sock);
+          return FOPENERR;
+        }
     }
   else
     fp = output_stream;
