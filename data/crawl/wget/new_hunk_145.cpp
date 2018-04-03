{
  const char *result;

  printf ("[DEBUG] Testing...\n\n");
#ifdef ENABLE_NLS
  /* Set the current locale.  */
  setlocale (LC_ALL, "");
