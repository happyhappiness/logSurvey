  return false;
}

/* Decodes a single extended header record. Advances P to the next
   record.
   Returns true on success, false otherwise. */
static bool
decode_record (char **p,
	       void (*handler) (void *, char const *, char const *),
	       void *data)
{
  size_t len;
  char const *keyword;
  char *start = *p;
  char endc;

  if (**p == 0)
    return false;

  len = strtoul (*p, p, 10);
  if (**p != ' ')
    {
      ERROR ((0, 0,
       _("Malformed extended header: missing whitespace after the length")));
      return false;
    }

  keyword = ++*p;
  for (;*p < start + len; ++*p)
    if (**p == '=')
      break;

  if (**p != '=')
    {
      ERROR ((0, 0, _("Malformed extended header: missing equal sign")));
      return false;
    }

  **p = 0;

  endc = start[len-1];
  start[len-1] = 0;

  handler (data, keyword, *p + 1);

  start[len-1] = endc;
  **p = '=';
  *p = &start[len];
  return true;
}

