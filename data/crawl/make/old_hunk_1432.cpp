  if (!f->is_target)
    puts ("# Not a target:");
  printf ("%s:%s", f->name, f->double_colon ? ":" : "");
	      
  for (d = f->deps; d != 0; d = d->next)
    printf (" %s", dep_name (d));
  putchar ('\n');
	      
  if (f->precious)
    puts ("#  Precious file (dependency of .PRECIOUS).");
  if (f->phony)
