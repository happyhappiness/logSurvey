
      if (status == 0)
	{
	  print_for_mkdir (file_name, cursor - file_name,
			   ~newdir_umask & MODE_RWX);
	  did_something = 1;
