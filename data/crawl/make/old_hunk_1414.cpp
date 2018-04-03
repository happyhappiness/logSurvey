    error("Resetting make for single job mode.");
    job_slots = 1;
  }
#endif /* WIN32 */

  /* Define the default variables.  */
  define_default_variables ();
