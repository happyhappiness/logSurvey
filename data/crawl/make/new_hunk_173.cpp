  len = e - name;

  if (len == 0)
    O (fatal, flocp, _("Empty function name"));
  if (*name == '.' || *e != '\0')
    OS (fatal, flocp, _("Invalid function name: %s"), name);
  if (len > 255)
    OS (fatal, flocp, _("Function name too long: %s"), name);
  if (min > 255)
    ONS (fatal, flocp,
         _("Invalid minimum argument count (%d) for function %s"), min, name);
  if (max > 255 || (max && max < min))
    ONS (fatal, flocp,
         _("Invalid maximum argument count (%d) for function %s"), max, name);

  ent = xmalloc (sizeof (struct function_table_entry));
  ent->name = name;
