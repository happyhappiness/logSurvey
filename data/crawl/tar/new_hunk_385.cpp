  if (file)
    {
      fprintf (file, "%d\n", global_volno);
      if (ferror (file))
	write_error (volno_file_option);
      if (fclose (file) != 0)
	close_error (volno_file_option);
    }
  else
    open_error (volno_file_option);
}

/*-----------------------------------------------------------------------.
