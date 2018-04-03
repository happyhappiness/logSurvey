#ifdef HAVE_STRNDUP
  result = strndup (str, length);
  if (result == 0)
    OUT_OF_MEM();
#else
  result = xmalloc (length + 1);
  if (length > 0)
