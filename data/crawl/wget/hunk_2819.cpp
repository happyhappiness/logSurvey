 		{
 		  if (contlen >= 1024)
 		    logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
-			       with_thousand_seps (contlen),
+			       number_to_static_string (contlen),
 			       human_readable (contlen));
 		  else
 		    logprintf (LOG_VERBOSE, _(", %s remaining"),
-			       with_thousand_seps (contlen));
+			       number_to_static_string (contlen));
 		}
 	    }
 	  else
