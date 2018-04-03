/* Print out the commands in CMDS.  */

void
print_commands (struct commands *cmds)
{
  register char *s;

  fputs (_("#  commands to execute"), stdout);

