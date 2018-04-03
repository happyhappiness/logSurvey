  if (prev_fail || fclose_fail)
    {
      if (fclose_fail)
        error (NILF, _("write error: %s"), strerror (errno));
      else
        error (NILF, _("write error"));
      exit (EXIT_FAILURE);
    }
}
