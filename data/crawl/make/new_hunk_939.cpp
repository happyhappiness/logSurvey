  ofile[0] = 0;
  efile[0] = 0;

  DB (DB_JOBS, ("child_execute_job (%s)\n", argv));

  while (isspace (*argv))
    argv++;
