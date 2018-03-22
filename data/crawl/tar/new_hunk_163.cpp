  return false;
}

/* Decode a single extended header record, advancing *PTR to the next record.
   Return true on success, false otherwise.  */
static bool
decode_record (char **ptr,
	       void (*handler) (void *, char const *, char const *),
	       void *data)
{
  char *start = *ptr;
  char *p = start;
  unsigned long int len;
  char *len_lim;
  char const *keyword;
  char *nextp;
  size_t len_max = extended_header.buffer + extended_header.size - start;

  while (*p == ' ' || *p == '\t')
    p++;

  if (! ISDIGIT (*p))
    {
      if (*p)
	ERROR ((0, 0, _("Malformed extended header: missing length")));
      return false;
    }

  errno = 0;
  len = strtoul (p, &len_lim, 10);

  if (len_max < len || (len == ULONG_MAX && errno == ERANGE))
    {
      ERROR ((0, 0, _("Malformed extended header: length out of range")));
      return false;
    }

  nextp = start + len;

  for (p = len_lim; *p == ' ' || *p == '\t'; p++)
    continue;
  if (p == len_lim)
    {
      ERROR ((0, 0,
	      _("Malformed extended header: missing blank after length")));
      return false;
    }

  keyword = p;
  p = strchr (p, '=');
  if (! (p && p < nextp))
    {
      ERROR ((0, 0, _("Malformed extended header: missing equal sign")));
      return false;
    }

  if (nextp[-1] != '\n')
    {
      ERROR ((0, 0, _("Malformed extended header: missing newline")));
      return false;
    }

  *p = nextp[-1] = '\0';
  handler (data, keyword, p + 1);
  *p = '=';
  nextp[-1] = '\n';
  *ptr = nextp;
  return true;
}

