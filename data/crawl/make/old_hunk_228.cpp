    size = 1;
  result = ptr ? realloc (ptr, size) : malloc (size);
  if (result == 0)
    fatal (NILF, _("virtual memory exhausted"));
  return result;
}
