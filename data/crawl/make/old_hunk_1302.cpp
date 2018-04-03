{
  char *result = (char *) realloc (ptr, size);
  if (result == 0)
    fatal ("virtual memory exhausted");
  return result;
}

