  use_ts = 0;
  if (opt.timestamping)
    {
      if (stat (u->local, &st) == 0)
	{
	  use_ts = 1;
	  tml = st.st_mtime;
