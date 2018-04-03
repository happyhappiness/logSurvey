  hash_init_function_table ();
}

static const char *
expand_command_line_file (char *name)
{
  const char *cp;
  char *expanded = 0;

  if (name[0] == '\0')
    fatal (NILF, _("empty string invalid as file name"));

  if (name[0] == '~')
    {
      expanded = tilde_expand (name);
      if (expanded != 0)
	name = expanded;
    }

  /* This is also done in parse_file_seq, so this is redundant
