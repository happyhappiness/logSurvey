  if (file)
    {
      fscanf (file, "%d", &global_volno);
      if (fclose (file) == EOF)
	ERROR ((0, errno, "%s", volno_file_option));
    }
  else if (errno != ENOENT)
    ERROR ((0, errno, "%s", volno_file_option));
}

/*-------------------------------------------------------.
