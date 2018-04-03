	  }

	case 0:
	re_exec:;
	  /* Updated successfully.  Re-exec ourselves.  */
	  if (print_directory_flag)
	    log_working_directory (0);
	  if (debug_flag)
	    puts ("Re-execing myself....");
	  if (makefiles != 0)
	    {
	      /* These names might have changed.  */
