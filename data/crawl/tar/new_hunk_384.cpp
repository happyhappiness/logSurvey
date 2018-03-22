  if (file)
    {
      fscanf (file, "%d", &global_volno);
      if (ferror (file))
	read_error (volno_file_option);
      if (fclose (file) != 0)
	close_error (volno_file_option);
    }
  else if (errno != ENOENT)
    open_error (volno_file_option);
}

/*-------------------------------------------------------.
