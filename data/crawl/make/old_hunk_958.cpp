{
  int i;
  static struct dsc$descriptor_s cmddsc;
#ifndef DONTWAITFORCHILD
  int spflags = 0;
#else
  int spflags = CLI$M_NOWAIT;
#endif
  int status;
  char cmd[4096],*p,*c;
  char comname[50];

/* Remove backslashes */
  for (p = argv, c = cmd; *p; p++,c++)
    {
      if (*p == '\\') p++;
	*c = *p;
    }
  *c = *p;

  /* Check for maximum DCL length and create *.com file if neccesary.
     Also create a .com file if the command is more than one line long.  */

  comname[0] = '\0';

  if (strlen (cmd) > MAXCMDLEN || strchr (cmd, '\n'))
    {
      FILE *outfile;
      char tmp;

      strcpy (comname, "sys$scratch:CMDXXXXXX.COM");
      (void) mktemp (comname);
