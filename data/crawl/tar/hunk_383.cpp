       while (waitpid (child_pid, &wait_status, 0) == -1)
 	if (errno != EINTR)
 	  {
-	    ERROR ((0, errno, _("While waiting for child")));
+	    waitpid_error (use_compress_program_option);
 	    break;
 	  }
 
