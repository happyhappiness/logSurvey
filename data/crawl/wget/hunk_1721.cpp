 	      if (!exists)
 		{
 		  logputs (LOG_VERBOSE, "\n");
-		  logprintf (LOG_NOTQUIET, _("No such file `%s'.\n"),
-			     escnonprint (u->file));
+		  logprintf (LOG_NOTQUIET, _("No such file %s.\n"),
+			     quote (u->file));
 		}
 	    }
           fd_close (csock);
