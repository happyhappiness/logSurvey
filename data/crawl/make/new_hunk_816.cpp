      message (1, _("$SHELL changed (was `%s', now `%s')"), default_shell, shell);
      unixy_shell = _is_unixy_shell (shell);
      default_shell = shell;
      /* we must allocate a copy of shell: construct_command_argv() will free
       * shell after this function returns.  */
      default_shell = xmalloc (strlen (shell) + 1);
      strcpy (default_shell, shell);
    }
  if (unixy_shell)
    {
