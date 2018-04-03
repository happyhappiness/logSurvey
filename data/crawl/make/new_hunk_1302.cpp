{
  char *result = (char *) realloc (ptr, size);
  if (result == 0)
    fatal (NILF, "virtual memory exhausted");
  return result;
}

