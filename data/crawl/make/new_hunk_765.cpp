    /* If there were no command-line goals, use the default.  */
    if (goals == 0)
      {
        if (**default_target_name != '\0')
          {
            if (default_goal_file == 0 ||
                strcmp (*default_target_name, default_goal_file->name) != 0)
              {
                default_goal_file = lookup_file (*default_target_name);

                /* In case user set .DEFAULT_TARGET to a non-existent target
                   name let's just enter this name into the table and let
                   the standard logic sort it out. */
                if (default_goal_file == 0)
                  {
                    struct nameseq *ns;
                    char *p = *default_target_name;

                    ns = multi_glob (
                      parse_file_seq (&p, '\0', sizeof (struct nameseq), 1),
                      sizeof (struct nameseq));

                    /* .DEFAULT_TARGET should contain one target. */
                    if (ns->next != 0)
                      fatal (NILF, _(".DEFAULT_TARGET contains more than one target"));

                    default_goal_file = enter_file (ns->name);

                    ns->name = 0; /* It was reused by enter_file(). */
                    free_ns_chain (ns);
                  }
              }

            goals = (struct dep *) xmalloc (sizeof (struct dep));
            goals->next = 0;
            goals->name = 0;
            goals->ignore_mtime = 0;
            goals->file = default_goal_file;
          }
      }
    else
      lastgoal->next = 0;


    if (!goals)
      {
        if (read_makefiles == 0)
