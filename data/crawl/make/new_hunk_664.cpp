static void			/* Useful to call from gdb.  */
print_rule (struct rule *r)
{
  unsigned int i;
  struct dep *d;

  for (i = 0; i < r->num; ++i)
    {
      fputs (r->targets[i], stdout);
      putchar ((i + 1 == r->num) ? ':' : ' ');
    }
  if (r->terminal)
    putchar (':');
