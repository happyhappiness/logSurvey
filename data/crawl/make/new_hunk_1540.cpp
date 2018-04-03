	  }

	case 0:
	re_exec:
	  /* Updated successfully.  Re-exec ourselves.  */

	  remove_intermediates (0);

	  if (print_data_base_flag)
	    print_data_base ();

	  if (print_directory_flag)
	    log_working_directory (0);

	  if (makefiles != 0)
	    {
	      /* These names might have changed.  */
