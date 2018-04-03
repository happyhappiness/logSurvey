 	}
     }
 
-  if (contrange == 0 && hs->restval > 0)
+  if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE)
     {
-      /* The download starts from the beginning, presumably because
-	 the server did not honor our `Range' request.  Normally we'd
-	 just reset hs->restval and start the download from
-	 scratch.  */
-
-      /* However, if `-c' is used, we need to be a bit more careful:
-
-         1. If `-c' is specified and the file already existed when
-         Wget was started, it would be a bad idea to start downloading
-         it from scratch, effectively truncating the file.
-
-	 2. If `-c' is used on a file that is already fully
-	 downloaded, we're requesting bytes after the end of file,
-	 which can result in the server not honoring `Range'.  If this
-	 is the case, `Content-Length' will be equal to the length of
-	 the file.  */
-      if (opt.always_rest)
-	{
-	  /* Check for condition #2. */
-	  if (contlen != -1              /* we got content-length. */
-	      && hs->restval >= contlen  /* file fully downloaded
-					    or has shrunk.  */
-	      )
-	    {
-	      logputs (LOG_VERBOSE, _("\
+      /* If `-c' is in use and the file has been fully downloaded (or
+	 the remote file has shrunk), Wget effectively requests bytes
+	 after the end of file and the server response with 416.  */
+      logputs (LOG_VERBOSE, _("\
 \n    The file is already fully retrieved; nothing to do.\n\n"));
-	      /* In case the caller inspects. */
-	      hs->len = contlen;
-	      hs->res = 0;
-	      /* Mark as successfully retrieved. */
-	      *dt |= RETROKF;
-	      xfree_null (type);
-	      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
-					   might be more bytes in the body. */
-	      return RETRUNNEEDED;
-	    }
-
-	  /* Check for condition #1. */
-	  if (hs->no_truncate)
-	    {
-	      logprintf (LOG_NOTQUIET,
-			 _("\
-\n\
-Continued download failed on this file, which conflicts with `-c'.\n\
-Refusing to truncate existing file `%s'.\n\n"), *hs->local_file);
-	      xfree_null (type);
-	      CLOSE_INVALIDATE (sock); /* see above */
-	      return CONTNOTSUPPORTED;
-	    }
-
-	  /* Fallthrough */
-	}
-
-      hs->restval = 0;
+      /* In case the caller inspects. */
+      hs->len = contlen;
+      hs->res = 0;
+      /* Mark as successfully retrieved. */
+      *dt |= RETROKF;
+      xfree_null (type);
+      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
+				   might be more bytes in the body. */
+      return RETRUNNEEDED;
     }
-  else if (contrange != hs->restval ||
-	   (H_PARTIAL (statcode) && contrange == -1))
+  if ((contrange != 0 && contrange != hs->restval)
+      || (H_PARTIAL (statcode) && !contrange))
     {
-      /* This means the whole request was somehow misunderstood by the
-	 server.  Bail out.  */
+      /* The Range request was somehow misunderstood by the server.
+	 Bail out.  */
       xfree_null (type);
       CLOSE_INVALIDATE (sock);
       return RANGEERR;
