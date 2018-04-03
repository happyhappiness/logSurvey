enter_command_line_file (name)
     char *name;
{
  if (name[0] == '~')
    {
      char *expanded = tilde_expand (name);
