  rv = fake_fork_child ();
  if (rv < 0)
    {
      fprintf (stderr, _("fake_fork_child() failed\n"));
      abort ();
    }
  else if (rv == 0)
