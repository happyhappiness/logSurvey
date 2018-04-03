 	  d->file->command_state = f->command_state;
 	  d->file->update_status = f->update_status;
 	  d->file->updated = f->updated;
+	  if (debug_flag)
+	    {
+	      print_spaces (depth);
+	      printf ("File `%s' was also made by making `%s'.\n",
+		      d->file->name, f->name);
+	    }
 	}
 
       if (status != 0 && !keep_going_flag)
