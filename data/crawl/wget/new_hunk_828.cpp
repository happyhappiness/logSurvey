  /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is 
     absent. */
  printf (wgetrc_title);
  env_wgetrc = wgetrc_env_file_name ();
  if (env_wgetrc && *env_wgetrc) 
    {
      printf ("%s (env)\n%s", env_wgetrc, prefix_spaces);
      xfree (env_wgetrc);
    }
  user_wgetrc = wgetrc_user_file_name ();
  if (user_wgetrc) 
    {
      printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
