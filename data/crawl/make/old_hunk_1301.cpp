{
  char *result = (char *) malloc (size);
  if (result == 0)
    fatal ("virtual memory exhausted");
  return result;
}

