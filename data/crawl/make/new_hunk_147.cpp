                           &bufdesc.dsc$w_length, 0);
  if (! (status & 1))
    {
      ON (error, NILF,
          _("lbr$set_module() failed to extract module info, status = %d"),
          status);

      lbr$close (&VMS_lib_idx);

