
  l += strlen (pre) + strlen (post);

  if (exit_sig == 0)
    error (NILF, l + INTSTR_LENGTH,
           _("%s[%s] Error %d%s"), pre, f->name, exit_code, post);
