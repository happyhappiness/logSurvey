}

void
define_new_function (const gmk_floc *flocp,
                     const char *name, int min, int max, int expand,
                     char *(*func)(const char *, int, char **))
{
  struct function_table_entry *ent;
  size_t len = strlen (name);

  if (len > 255)
    fatal (flocp, _("Function name too long: %s\n"), name);
  if (min < 0 || min > 255)
    fatal (flocp, _("Invalid minimum argument count (%d) for function %s\n"),
           min, name);
  if (max < 0 || max > 255 || (max && max < min))
    fatal (flocp, _("Invalid maximum argument count (%d) for function %s\n"),
           max, name);

