 	case FT_DIRECTORY:
 	  if (!opt.recursive)
 	    logprintf (LOG_NOTQUIET, _("Skipping directory `%s'.\n"),
-		       f->name);
+		       escnonprint (f->name));
 	  break;
 	case FT_PLAINFILE:
 	  /* Call the retrieve loop.  */
