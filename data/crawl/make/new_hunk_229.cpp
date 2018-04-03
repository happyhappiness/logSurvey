#endif

  if (result == 0)
    OUT_OF_MEM();

#ifdef HAVE_STRDUP
  return result;
