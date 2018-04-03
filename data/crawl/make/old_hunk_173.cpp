  len = e - name;

  if (len == 0)
    fatal (flocp, _("Empty function name\n"));
  if (*name == '.' || *e != '\0')
    fatal (flocp, _("Invalid function name: %s\n"), name);
  if (len > 255)
    fatal (flocp, _("Function name too long: %s\n"), name);
  if (min > 255)
    fatal (flocp, _("Invalid minimum argument count (%d) for function %s\n"),
           min, name);
  if (max > 255 || (max && max < min))
    fatal (flocp, _("Invalid maximum argument count (%d) for function %s\n"),
           max, name);

  ent = xmalloc (sizeof (struct function_table_entry));
  ent->name = name;
