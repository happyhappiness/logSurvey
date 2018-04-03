 	  return 0;
 
 	default:
-	  error ("internal error: `%s' command_state == %d in update_file",
-		 f->name, (int) f->command_state);
-	  abort ();
+	  assert (f->command_state == cs_running);
 	  break;
 	}
     }
