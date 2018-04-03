      nm = a;
    }

  OUTPUT_SET (&child->output);

  message (0, _("%s: recipe for target '%s' failed"), nm, f->name);

#ifdef VMS
  if ((exit_code & 1) != 0)
    {
      OUTPUT_UNSET ();
      return;
    }

  error (NILF, _("%s[%s] Error 0x%x%s"), pre, f->name, exit_code, post);
#else
  if (exit_sig == 0)
    error (NILF, _("%s[%s] Error %d%s"), pre, f->name, exit_code, post);
  else
    {
      const char *s = strsignal (exit_sig);
      error (NILF, _("%s[%s] %s%s%s"), pre, f->name, s, dump, post);
    }
#endif /* VMS */

  OUTPUT_UNSET ();
}


