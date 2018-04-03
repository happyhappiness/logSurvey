 	  logprintf (LOG_NOTQUIET, _("Cannot write to `%s' (%s).\n"),
 		     u->local, strerror (errno));
 	  FREEHSTAT (hstat);
+	  return err;
+	  break;
+   case CONSSLERR:
+	  /* Another fatal error.  */
+	  logputs (LOG_VERBOSE, "\n");
+	  logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
+	  FREEHSTAT (hstat);
 	  xfree (filename_plus_orig_suffix); /* must precede every return! */
 	  return err;
 	  break;
