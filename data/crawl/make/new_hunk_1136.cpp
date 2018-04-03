    if (!goals)
      {
        if (read_makefiles == 0)
          fatal (NILF, _("No targets specified and no makefile found"));

        fatal (NILF, _("No targets"));
      }

    /* Update the goals.  */

    if (debug_flag)
      puts (_("Updating goal targets...."));

    switch (update_goal_chain (goals, 0))
    {
