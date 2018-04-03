{
  char *result = (char *) malloc (size);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
  return result;
}

