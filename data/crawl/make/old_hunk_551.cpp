#ifdef VMS

/* VMS can't do $(shell ...)  */
#define func_shell 0

#else
#ifndef _AMIGA
static char *
func_shell (char *o, char **argv, const char *funcname UNUSED)
{
  char *batch_filename = NULL;

