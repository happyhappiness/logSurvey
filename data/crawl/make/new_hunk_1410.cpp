      free(s2);
  }
  if (slow_flag)
    goto slow;
#else  /* not WINDOWS32 */
#ifdef __MSDOS__
  else if (stricmp (shell, default_shell))
    {
      extern int _is_unixy_shell (const char *_path);

      message (1, "$SHELL changed (was `%s', now `%s')", default_shell, shell);
      unixy_shell = _is_unixy_shell (shell);
      default_shell = shell;
    }
  if (unixy_shell)
    {
      sh_chars = sh_chars_sh;
      sh_cmds  = sh_cmds_sh;
    }
  else
    {
      sh_chars = sh_chars_dos;
      sh_cmds  = sh_cmds_dos;
    }
#else  /* not __MSDOS__ */
  else if (strcmp (shell, default_shell))
    goto slow;
#endif /* not __MSDOS__ */
#endif /* not WINDOWS32 */

  if (ifs != 0)
    for (ap = ifs; *ap != '\0'; ++ap)
