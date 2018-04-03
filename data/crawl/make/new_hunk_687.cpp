      if (print_data_base_flag)
	print_data_base ();

      clean_jobserver (status);

      /* Try to move back to the original directory.  This is essential on
	 MS-DOS (where there is really only one process), and on Unix it
