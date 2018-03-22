	write_error (name);
      else if (count != written)
	{
	  write_error_details (name, count, written);
	  skip_file (*sizeleft);
	}

