
  home = home_dir ();
  if (home)
    return aprintf ("%s/.wget-hsts", home);

  return NULL;
}
