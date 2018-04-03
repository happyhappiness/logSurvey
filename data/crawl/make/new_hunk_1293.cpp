    else
      {
	if (read_makefiles == 0)
	  fatal (NILF, "No targets specified and no makefile found");
	else
	  fatal (NILF, "No targets");
      }

    /* If we detected some clock skew, generate one last warning */
    if (clock_skew_detected)
      error (NILF, "*** Warning:  Clock skew detected.  Your build may be incomplete.");

    /* Exit.  */
    die (status);
