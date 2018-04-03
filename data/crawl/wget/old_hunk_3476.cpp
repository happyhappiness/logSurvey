  else if (pid != 0)
    {
      /* parent, no error */
      printf (_("Continuing in background.\n"));
      if (changedp)
	printf (_("Output will be written to `%s'.\n"), opt.lfilename);
      exit (0);
    }
  /* child: keep running */
}
#endif /* not WINDOWS */

