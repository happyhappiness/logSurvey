      printf ("\n");
    }
  printf ("\n");
  /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is
     absent. */
  printf ("%s\n", wgetrc_title);
  env_wgetrc = wgetrc_env_file_name ();
  if (env_wgetrc && *env_wgetrc)
    {
      printf (_("    %s (env)\n"), env_wgetrc);
      xfree (env_wgetrc);
    }
  user_wgetrc = wgetrc_user_file_name ();
  if (user_wgetrc)
    {
      printf (_("    %s (user)\n"), user_wgetrc);
      xfree (user_wgetrc);
