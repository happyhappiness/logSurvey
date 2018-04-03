 	    break;
 
 	  default:
-	    error (NILF, "internal error: `%s' command_state", c->file->name);
+	    error (NILF, _("internal error: `%s' command_state"), c->file->name);
 	    abort ();
 	    break;
 	  }
