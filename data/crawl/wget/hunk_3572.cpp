 	  /* Non-fatal errors continue executing the loop, which will
 	     bring them to "while" statement at the end, to judge
 	     whether the number of tries was exceeded.  */
-	  FREEHSTAT (hstat);
+	  free_hstat (&hstat);
 	  printwhat (count, opt.ntry);
 	  continue;
 	  break;
 	case HOSTERR: case CONREFUSED: case PROXERR: case AUTHFAILED: 
 	case SSLERRCTXCREATE: case CONTNOTSUPPORTED:
 	  /* Fatal errors just return from the function.  */
-	  FREEHSTAT (hstat);
+	  free_hstat (&hstat);
+	  FREE_MAYBE (dummy);
 	  return err;
 	  break;
 	case FWRITEERR: case FOPENERR:
 	  /* Another fatal error.  */
 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET, _("Cannot write to `%s' (%s).\n"),
-		     u->local, strerror (errno));
-	  FREEHSTAT (hstat);
+		     *hstat.local_file, strerror (errno));
+	  free_hstat (&hstat);
+	  FREE_MAYBE (dummy);
 	  return err;
 	  break;
 	case CONSSLERR:
 	  /* Another fatal error.  */
 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
-	  FREEHSTAT (hstat);
+	  free_hstat (&hstat);
+	  FREE_MAYBE (dummy);
 	  return err;
 	  break;
 	case NEWLOCATION:
