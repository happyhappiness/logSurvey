      nm = a;
    }

  msg = message_s (strlen (nm) + strlen (f->name), 0,
                   _("%s: recipe for target '%s' failed"), nm, f->name);
  child_out (child, msg, 1);

  l = strlen (pre) + strlen (f->name) + strlen (post);

#ifdef VMS
  if ((exit_code & 1) != 0)
    return;

  msg = error_s (l + INTEGER_LENGTH, NILF,
                 _("%s[%s] Error 0x%x%s"), pre, f->name, exit_code, post);
#else
  if (exit_sig == 0)
    msg = error_s (l + INTEGER_LENGTH, NILF,
                   _("%s[%s] Error %d%s"), pre, f->name, exit_code, post);
  else
    {
      const char *s = strsignal (exit_sig);
      msg = error_s (l + strlen (s) + strlen (dump), NILF,
                     _("%s[%s] %s%s%s"), pre, f->name, s, dump, post);
    }
#endif /* VMS */

  child_out (child, msg, 0);
}


