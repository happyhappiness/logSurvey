    /* search token path was found */
    sprintf(sh_path, "%s", search_token);
    default_shell = xstrdup(w32ify(sh_path,0));
    DB (DB_EXTRA,
        (_("find_and_set_shell setting default_shell = %s\n"), default_shell));
    sh_found = 1;
  } else {
    char *p;
