
  if (! (status & 1))
    {
      error (NILF, _("lbr$ini_control failed with status = %d"),status);
      return -2;
    }

