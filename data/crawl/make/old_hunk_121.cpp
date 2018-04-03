long int
ar_scan (const char *archive, ar_member_func_t function, const void *varg)
{
  char *p;
  const char *arg = varg;

  static struct dsc$descriptor_s libdesc =
    { 0, DSC$K_DTYPE_T, DSC$K_CLASS_S, NULL };

  unsigned long func = LBR$C_READ;
  unsigned long type = LBR$C_TYP_UNK;
  unsigned long index = 1;

  int status;

  status = lbr$ini_control (&VMS_lib_idx, &func, &type, 0);

  if (! (status & 1))
    {
      ON (error, NILF, _("lbr$ini_control() failed with status = %d"), status);
      return -2;
    }

  /* there is no such descriptor with "const char *dsc$a_pointer" */
  libdesc.dsc$a_pointer = (char *)archive;
  libdesc.dsc$w_length = strlen (archive);

  status = lbr$open (&VMS_lib_idx, &libdesc, 0, 0, 0, 0, 0);

  if (! (status & 1))
    {
      OSS (error, NILF, _("unable to open library '%s' to lookup member '%s'"),
           archive, arg);
      return -1;
    }

  VMS_saved_memname = arg;

  /* For comparison, delete .obj from arg name.  */

  p = strrchr (VMS_saved_memname, '.');
  if (p)
    *p = '\0';

  VMS_function = function;

  VMS_member_date = (time_t) -1;
  lbr$get_index (&VMS_lib_idx, &index, VMS_get_member_info, 0);

  /* Undo the damage.  */
  if (p)
    *p = '.';

  lbr$close (&VMS_lib_idx);

  return VMS_member_date > 0 ? VMS_member_date : 0;
}

#else /* !VMS */
