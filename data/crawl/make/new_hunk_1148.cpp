#endif

  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));

#ifdef HAVE_STRDUP
  return result;
