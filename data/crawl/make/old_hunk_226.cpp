  /* Make sure we don't allocate 0, for pre-ISO implementations.  */
  void *result = malloc (size ? size : 1);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
  return result;
}

