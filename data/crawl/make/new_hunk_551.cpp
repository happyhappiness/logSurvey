#ifdef VMS

/* VMS can't do $(shell ...)  */

char *
func_shell_base (char *o, char **argv, int trim_newlines)
{
  fprintf (stderr, "This platform does not support shell\n");
  die (EXIT_FAILURE);
}

#define func_shell 0

#else
#ifndef _AMIGA
char *
func_shell_base (char *o, char **argv, int trim_newlines)
{
  char *batch_filename = NULL;

