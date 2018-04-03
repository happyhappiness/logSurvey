 	  logputs (LOG_VERBOSE, _("Length: "));
 	  if (contlen != -1)
 	    {
-	      logputs (LOG_VERBOSE, legible (contlen + contrange));
+	      logputs (LOG_VERBOSE, with_thousand_seps (contlen + contrange));
+	      if (contlen + contrange >= 1024)
+		logprintf (LOG_VERBOSE, " (%s)",
+			   human_readable (contlen + contrange));
 	      if (contrange)
-		logprintf (LOG_VERBOSE, _(" (%s to go)"), legible (contlen));
+		{
+		  if (contlen >= 1024)
+		    logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
+			       with_thousand_seps (contlen),
+			       human_readable (contlen));
+		  else
+		    logprintf (LOG_VERBOSE, _(", %s remaining"),
+			       with_thousand_seps (contlen));
+		}
 	    }
 	  else
 	    logputs (LOG_VERBOSE,
