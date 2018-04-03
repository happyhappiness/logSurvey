
  putchar ('\n');
  if (!f->is_target)
    puts ("# Not a target:");
  printf ("%s:%s", f->name, f->double_colon ? ":" : "");

  for (d = f->deps; d != 0; d = d->next)
