  if (file)
    {
      fprintf (file, "%d\n", global_volno);
      if (fclose (file) == EOF)
	ERROR ((0, errno, "%s", volno_file_option));
    }
  else
    ERROR ((0, errno, "%s", volno_file_option));
}

/*-----------------------------------------------------------------------.
