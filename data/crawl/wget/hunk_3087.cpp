 	  else if (!opt.kill_longer) /* meaning we got more than expected */
 	    {
 	      logprintf (LOG_VERBOSE,
-			 _("%s (%s) - `%s' saved [%ld/%ld])\n\n"),
-			 tms, tmrate, locf, hstat.len, hstat.contlen);
+			 _("%s (%s) - `%s' saved [%s/%s])\n\n"),
+			 tms, tmrate, locf,
+			 number_to_static_string (hstat.len),
+			 number_to_static_string (hstat.contlen));
 	      logprintf (LOG_NONVERBOSE,
-			 "%s URL:%s [%ld/%ld] -> \"%s\" [%d]\n",
-			 tms, u->url, hstat.len, hstat.contlen, locf, count);
+			 "%s URL:%s [%s/%s] -> \"%s\" [%d]\n",
+			 tms, u->url,
+			 number_to_static_string (hstat.len),
+			 number_to_static_string (hstat.contlen),
+			 locf, count);
 	      ++opt.numurls;
 	      total_downloaded_bytes += hstat.len;
 
