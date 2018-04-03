      OUTPUT_UNSET ();
      return;
    }

  error (NILF, l + INTSTR_LENGTH,
         _("%s[%s] Error 0x%x%s"), pre, f->name, exit_code, post);
#else
  if (exit_sig == 0)
    error (NILF, l + INTSTR_LENGTH,
