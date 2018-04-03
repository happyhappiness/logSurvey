
    /* If we detected some clock skew, generate one last warning */
    if (clock_skew_detected)
      O (error, NILF,
         _("warning:  Clock skew detected.  Your build may be incomplete."));

    /* Exit.  */
    die (makefile_status);
