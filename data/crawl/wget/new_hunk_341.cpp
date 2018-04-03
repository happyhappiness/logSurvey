prompt_for_password (void)
{
  if (opt.user)
    fprintf (stderr, _("Password for user %s: "), quote (opt.user));
  else
    fprintf (stderr, _("Password: "));
  return getpass("");
}

