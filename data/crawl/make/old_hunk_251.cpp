     at this time, since they won't get snapped and we'll get core dumps.
     See Savannah bug # 12124.  */
  if (snapped_deps)
    fatal (flocp, _("prerequisites cannot be defined in recipes"));

  /* Determine if this is a pattern rule or not.  */
  name = filenames->name;
