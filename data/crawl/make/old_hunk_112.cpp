
  l += strlen (pre) + strlen (post);

#ifdef VMS
  if ((exit_code & 1) != 0)
    {
      OUTPUT_UNSET ();
      return;
    }
  /* Check for a Posix compatible VMS style exit code:
     decode and print the Posix exit code */
  if ((exit_code & 0x35a000) == 0x35a000)
    error(NILF, l + INTSTR_LENGTH, _("%s[%s] Error %d%s"), pre, f->name,
        ((exit_code & 0x7f8) >> 3), post);
  else
    error(NILF, l + INTSTR_LENGTH, _("%s[%s] Error 0x%x%s"), pre, f->name,
        exit_code, post);
#else
  if (exit_sig == 0)
    error (NILF, l + INTSTR_LENGTH,
           _("%s[%s] Error %d%s"), pre, f->name, exit_code, post);
