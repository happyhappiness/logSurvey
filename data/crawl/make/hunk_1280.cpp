 	    break;
 
 	  default:
-	    error ("internal error: `%s' command_state \
-%d in child_handler", c->file->name);
+	    error (NILF, "internal error: `%s' command_state", c->file->name);
 	    abort ();
 	    break;
 	  }
