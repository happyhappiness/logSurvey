     }
 
   if (contrange == -1)
-    hs->restval = 0;
+    {
+      /* We did not get a content-range header.  This means that the
+	 server did not honor our `Range' request.  Normally, this
+	 means we should reset hs->restval and continue normally.  */
+
+      /* However, if `-c' is used, we need to be a bit more careful:
+
+         1. If `-c' is specified and the file already existed when
+         Wget was started, it would be a bad idea for us to start
+         downloading it from scratch, effectively truncating it.  I
+         believe this cannot happen unless `-c' was specified.
+
+	 2. If `-c' is used on a file that is already fully
+	 downloaded, we're requesting bytes after the end of file,
+	 which can result in server not honoring `Range'.  If this is
+	 the case, `Content-Length' will be equal to the length of the
+	 file.  */
+      if (opt.always_rest)
+	{
+	  /* Check for condition #2. */
+	  if (hs->restval == contlen)
+	    {
+	      logputs (LOG_VERBOSE, _("\
+\n    The file is already fully retrieved; nothing to do.\n\n"));
+	      /* In case the caller inspects. */
+	      hs->len = contlen;
+	      hs->res = 0;
+	      FREE_MAYBE (type);
+	      FREE_MAYBE (hs->newloc);
+	      FREE_MAYBE (all_headers);
+	      CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
+					   might be more bytes in the body. */
+	      return RETRFINISHED;
+	    }
+
+	  /* Check for condition #1. */
+	  if (hs->no_truncate)
+	    {
+	      logprintf (LOG_NOTQUIET,
+			 _("\
+
+    The server does not support continued download;
+    refusing to truncate `%s'.\n\n"), u->local);
+	      return CONTNOTSUPPORTED;
+	    }
+
+	  /* Fallthrough */
+	}
+
+      hs->restval = 0;
+    }
+
   else if (contrange != hs->restval ||
 	   (H_PARTIAL (statcode) && contrange == -1))
     {
