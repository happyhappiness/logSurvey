  if (snapped_deps)
    fatal (flocp, _("prerequisites cannot be defined in recipes"));

  if (commands_idx > 0)
    {
      cmds = xmalloc (sizeof (struct commands));
