 		  break;
 
 		default:
-		  error ("internal error: `%s' command_state \
-%d in child_handler", c->file->name);
+		  error ("internal error: `%s' has bogus command_state \
+%d in reap_children",
+			 c->file->name, c->file->command_state);
 		  abort ();
 		  break;
 		}
 	    }
 
-	  /* Set the state flag to say the commands have finished.  */
+	  /* Notice if the target of the commands has been changed.  */
 	  notice_finished_file (c->file);
 
 	  /* Remove the child from the chain and free it.  */
