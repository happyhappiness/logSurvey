#ifdef HAVE_STRNDUP
  result = strndup (str, length);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
#else
  result = xmalloc (length + 1);
  if (length > 0)
