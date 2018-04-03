
    /* If we detected some clock skew, generate one last warning */
    if (clock_skew_detected)
      error (NILF,
             _("warning:  Clock skew detected.  Your build may be incomplete."));

    /* Exit.  */
    die (status);
