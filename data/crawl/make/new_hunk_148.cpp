
  if (! (status & 1))
    {
      ON (error, NILF, _("lbr$ini_control() failed with status = %d"), status);
      return -2;
    }

