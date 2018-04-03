  return buf;
}

static char *
prompt_for_password (void)
{
  if (opt.user)
    printf (_("Password for user \"%s\": "), opt.user);
  else
    printf (_("Password: "));
  return getpass("");
}

static void
print_version (void)
{
