
  OUTPUT_SET (&child->output);

  l += strlen (pre) + strlen (post);

  if (exit_sig == 0)
    error (NILF, l + INTSTR_LENGTH,
           _("%s[%s: %s] Error %d%s"), pre, nm, f->name, exit_code, post);
  else
    {
      const char *s = strsignal (exit_sig);
      error (NILF, l + strlen (s) + strlen (dump),
             "%s[%s: %s] %s%s%s", pre, nm, f->name, s, dump, post);
    }

  OUTPUT_UNSET ();
