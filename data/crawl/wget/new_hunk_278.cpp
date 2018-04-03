      /* We're the parent.  */
      fake_fork ();
      /* If fake_fork() returns, it failed.  */
      fprintf (stderr, _("fake_fork() failed\n"));
      abort ();
    }
  /* If we get here, we're the child.  */
