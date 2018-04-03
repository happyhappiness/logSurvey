
  if (!must_make)
    {
      DEBUGPR ("No need to remake target `%s'.\n");
      notice_finished_file (file);
      return 0;
    }

  DEBUGPR ("Must remake target `%s'.\n");

  /* Now, take appropriate actions to remake the file.  */
  remake_file (file);

