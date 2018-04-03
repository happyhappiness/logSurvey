/* Print out the commands in CMDS.  */

void
print_commands (const struct commands *cmds)
{
  const char *s;

  fputs (_("#  commands to execute"), stdout);

