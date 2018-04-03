 	      logprintf (LOG_NOTQUIET,
 			 _("ERROR: Redirection (%d) without location.\n"),
 			 hstat.statcode);
+	      free_hstat (&hstat);
+	      FREE_MAYBE (dummy);
 	      return WRONGCODE;
 	    }
-	  FREEHSTAT (hstat);
+	  free_hstat (&hstat);
+	  FREE_MAYBE (dummy);
 	  return NEWLOCATION;
 	  break;
 	case RETRUNNEEDED:
 	  /* The file was already fully retrieved. */
-	  FREEHSTAT (hstat);
+	  free_hstat (&hstat);
+	  FREE_MAYBE (dummy);
 	  return RETROK;
 	  break;
 	case RETRFINISHED:
