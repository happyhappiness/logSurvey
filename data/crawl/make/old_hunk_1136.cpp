    if (!goals)
      {
        if (read_makefiles == 0)
          fatal (NILF, "No targets specified and no makefile found");

        fatal (NILF, "No targets");
      }

    /* Update the goals.  */

    if (debug_flag)
      puts ("Updating goal targets....");

    switch (update_goal_chain (goals, 0))
    {
