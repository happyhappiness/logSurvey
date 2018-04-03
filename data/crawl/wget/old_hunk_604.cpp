char *
rpl_strerror (int n)
{
  char *result = strerror (n);

  if (result == NULL || result[0] == '\0')
    {
      static char const fmt[] = "Unknown error (%d)";
      static char mesg[sizeof fmt + INT_STRLEN_BOUND (n)];
      sprintf (mesg, fmt, n);
      return mesg;
    }

  return result;
}

#endif
