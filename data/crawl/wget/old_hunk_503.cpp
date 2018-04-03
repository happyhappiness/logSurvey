  env_wgetrc = wgetrc_env_file_name ();
  if (env_wgetrc && *env_wgetrc) 
    {
      printf ("    %s (env)\n", env_wgetrc);
      xfree (env_wgetrc);
    }
  user_wgetrc = wgetrc_user_file_name ();
  if (user_wgetrc) 
    {
      printf ("    %s (user)\n", user_wgetrc);
      xfree (user_wgetrc);
    }
#ifdef SYSTEM_WGETRC
  printf ("    %s (system)\n", SYSTEM_WGETRC);
#endif

  format_and_print_line (locale_title,
