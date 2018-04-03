  char **targets = 0, **target_percents = 0;
  struct commands *cmds;

  /* If we've already snapped deps, that means we're in an eval being
     resolved after the makefiles have been read in.  We can't add more rules
     at this time, since they won't get snapped and we'll get core dumps.
     See Savannah bug # 12124.  */
  if (snapped_deps)
    fatal (flocp, _("prerequisites cannot be defined in command scripts"));

  if (commands_idx > 0)
    {
      cmds = (struct commands *) xmalloc (sizeof (struct commands));
