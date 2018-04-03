      sprintf (a, "%s:%lu", flocp->filenm, flocp->lineno);
      nm = a;
    }
  message (0, _("%s: recipe for target '%s' failed"), nm, file->name);

#ifdef VMS
  if (!(exit_code & 1))
    error (NILF, _("%s[%s] Error 0x%x%s"), pre, file->name, exit_code, post);
#else
  if (exit_sig == 0)
    error (NILF, _("%s[%s] Error %d%s"), pre, file->name, exit_code, post);
  else
    error (NILF, _("%s[%s] %s%s%s"),
           pre, file->name, strsignal (exit_sig), dump, post);
#endif /* VMS */
}


