  if (stdin_nm && unlink (stdin_nm) < 0 && errno != ENOENT)
    perror_with_name (_("unlink (temporary file): "), stdin_nm);

  {
    int status;

    /* If there were no command-line goals, use the default.  */
    if (goals == 0)
      {
        if (**default_goal_name != '\0')
          {
            if (default_goal_file == 0 ||
                strcmp (*default_goal_name, default_goal_file->name) != 0)
              {
                default_goal_file = lookup_file (*default_goal_name);

                /* In case user set .DEFAULT_GOAL to a non-existent target
                   name let's just enter this name into the table and let
                   the standard logic sort it out. */
                if (default_goal_file == 0)
                  {
                    struct nameseq *ns;
                    char *p = *default_goal_name;

                    ns = multi_glob (
                      parse_file_seq (&p, '\0', sizeof (struct nameseq), 1),
                      sizeof (struct nameseq));

                    /* .DEFAULT_GOAL should contain one target. */
                    if (ns->next != 0)
                      fatal (NILF, _(".DEFAULT_GOAL contains more than one target"));

                    default_goal_file = enter_file (strcache_add (ns->name));

                    ns->name = 0; /* It was reused by enter_file(). */
                    free_ns_chain (ns);
                  }
              }

            goals = alloc_dep ();
            goals->file = default_goal_file;
          }
      }
    else
      lastgoal->next = 0;


    if (!goals)
      {
        if (read_makefiles == 0)
          fatal (NILF, _("No targets specified and no makefile found"));

        fatal (NILF, _("No targets"));
      }

    /* Update the goals.  */

    DB (DB_BASIC, (_("Updating goal targets....\n")));

    switch (update_goal_chain (goals))
    {
