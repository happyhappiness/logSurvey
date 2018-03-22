}

void
tar_list_quoting_styles (FILE *fp, char *prefix)
{
  int i;

  for (i = 0; quoting_style_args[i]; i++)
    fprintf (fp, "%s%s\n", prefix, quoting_style_args[i]);
}

void
