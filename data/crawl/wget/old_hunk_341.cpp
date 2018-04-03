prompt_for_password (void)
{
  if (opt.user)
    printf (_("Password for user %s: "), quote (opt.user));
  else
    printf (_("Password: "));
  return getpass("");
}

