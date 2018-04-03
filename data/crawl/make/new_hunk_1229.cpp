    else
      lastgoal->next = 0;

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
      case -1:
        /* Nothing happened.  */
      case 0:
        /* Updated successfully.  */
        status = EXIT_SUCCESS;
        break;
      case 2:
        /* Updating failed.  POSIX.2 specifies exit status >1 for this;
           but in VMS, there is only success and failure.  */
        status = EXIT_FAILURE ? 2 : EXIT_FAILURE;
        break;
      case 1:
        /* We are under -q and would run some commands.  */
        status = EXIT_FAILURE;
        break;
      default:
        abort ();
    }

    /* If we detected some clock skew, generate one last warning */
    if (clock_skew_detected)
      error (NILF, "*** Warning:  Clock skew detected.  Your build may be incomplete.");
