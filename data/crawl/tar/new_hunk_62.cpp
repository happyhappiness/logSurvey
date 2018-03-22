}

void
tar_list_quoting_styles (struct obstack *stk, char *prefix)
{
  int i;
  size_t prefixlen = strlen (prefix);
  
  for (i = 0; quoting_style_args[i]; i++)
    {
      obstack_grow (stk, prefix, prefixlen);
      obstack_grow (stk, quoting_style_args[i],
		    strlen (quoting_style_args[i]));
      obstack_1grow (stk, '\n');
    }
}

void
