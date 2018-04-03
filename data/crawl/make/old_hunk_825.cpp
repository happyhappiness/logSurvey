}

static struct file *
enter_command_line_file (name)
     char *name;
{
  if (name[0] == '\0')
    fatal (NILF, _("empty string invalid as file name"));
