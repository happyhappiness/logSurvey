    {
      extern int _is_unixy_shell (const char *_path);

      message (1, "$SHELL changed (was `%s', now `%s')", default_shell, shell);
      unixy_shell = _is_unixy_shell (shell);
      default_shell = shell;
    }
