  return result;
}


const char *
xstrdup (ptr)
     const char *ptr;
{
  char *result;

#ifdef HAVE_STRDUP
  result = strdup (ptr);
#else
  result = (char *) malloc (strlen (ptr) + 1);
#endif

  if (result == 0)
    fatal (NILF, "virtual memory exhausted");

#ifdef HAVE_STRDUP
  return result;
#else
  return strcpy(result, ptr);
#endif
}

char *
savestring (str, length)
     char *str;
