
/* Print the data base of rules.  */

static void			/* Useful to call from gdb.  */
print_rule (r)
     struct rule *r;
{
  register unsigned int i;
  register struct dep *d;

  for (i = 0; r->targets[i] != 0; ++i)
    {
      fputs (r->targets[i], stdout);
      if (r->targets[i + 1] != 0)
	putchar (' ');
      else
	putchar (':');
    }
  if (r->terminal)
    putchar (':');

  for (d = r->deps; d != 0; d = d->next)
    printf (" %s", dep_name (d));
  putchar ('\n');

  if (r->cmds != 0)
    print_commands (r->cmds);
}

void
print_rule_data_base ()
{
  register unsigned int rules, terminal;
  register struct rule *r;

  puts ("\n# Implicit Rules");

