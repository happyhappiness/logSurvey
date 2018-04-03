 	  break;
 	case FT_UNKNOWN:
 	  logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
-		     f->name);
+		     escnonprint (f->name));
 	  break;
 	}	/* switch */
 
