 	      logprintf (LOG_NOTQUIET,
 			 _("ERROR: Redirection (%d) without location.\n"),
 			 hstat.statcode);
-	      free(filename_plus_orig_suffix);  /* must precede every return! */
+	      xfree (filename_plus_orig_suffix); /* must precede every return! */
 	      return WRONGCODE;
 	    }
 	  FREEHSTAT (hstat);
-	  free(filename_plus_orig_suffix);  /* must precede every return! */
+	  xfree (filename_plus_orig_suffix); /* must precede every return! */
 	  return NEWLOCATION;
 	  break;
 	case RETRFINISHED:
