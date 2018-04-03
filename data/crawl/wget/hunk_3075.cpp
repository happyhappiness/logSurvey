 	  con->csock = -1;
 	}
       if (!opt.spider)
-        logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%ld]\n\n"),
-		   tms, tmrate, locf, len);
+        logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%s]\n\n"),
+		   tms, tmrate, locf, number_to_static_string (len));
       if (!opt.verbose && !opt.quiet)
 	{
 	  /* Need to hide the password from the URL.  The `if' is here
              so that we don't do the needless allocation every
              time. */
 	  char *hurl = url_string (u, 1);
-	  logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
-		     tms, hurl, len, locf, count);
+	  logprintf (LOG_NONVERBOSE, "%s URL: %s [%s] -> \"%s\" [%d]\n",
+		     tms, hurl, number_to_static_string (len), locf, count);
 	  xfree (hurl);
 	}
 
