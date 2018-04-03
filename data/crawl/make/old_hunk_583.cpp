    fatal (NILF, _("virtual memory exhausted"));
#else
  result = xmalloc (length + 1);
  strncpy (result, str, length);
  result[length] = '\0';
#endif

