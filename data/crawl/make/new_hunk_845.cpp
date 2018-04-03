print_file (f)
     struct file *f;
{
  struct dep *d;
  struct dep *ood = 0;

  putchar ('\n');
  if (!f->is_target)
    puts (_("# Not a target:"));
  printf ("%s:%s", f->name, f->double_colon ? ":" : "");

  /* Print all normal dependencies; note any order-only deps.  */
  for (d = f->deps; d != 0; d = d->next)
    if (! d->ignore_mtime)
      printf (" %s", dep_name (d));
    else if (! ood)
      ood = d;

  /* Print order-only deps, if we have any.  */
  if (ood)
    {
      printf (" | %s", dep_name (ood));
      for (d = ood->next; d != 0; d = d->next)
        if (d->ignore_mtime)
          printf (" %s", dep_name (d));
    }

  putchar ('\n');

  if (f->precious)
