{
  if (ignored && silent_flag)
    return;
    
#ifdef VMS
  if (!(exit_code & 1))
      error (NILF,
