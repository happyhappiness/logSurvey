 	    break;
 
 	  default:
-	    argp_error (state, _("Unknown density: `%c'"), arg[0]);
+	    argp_error (state, _("Unknown density: '%c'"), arg[0]);
 	  }
 	sprintf (cursor, "%d", device);
 
