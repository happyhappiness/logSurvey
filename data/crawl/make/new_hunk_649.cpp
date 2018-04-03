func_basename_dir (char *o, char **argv, const char *funcname)
{
  /* Expand the argument.  */
  const char *p3 = argv[0];
  const char *p2;
  int doneany=0;
  unsigned int len=0;

  int is_basename= streq (funcname, "basename");
  int is_dir= !is_basename;

  while ((p2 = find_next_token (&p3, &len)) != 0)
    {
      const char *p = p2 + len;
      while (p >= p2 && (!is_basename  || *p != '.'))
        {
          if (IS_PATHSEP (*p))
            break;
          --p;
        }

      if (p >= p2 && (is_dir))
        o = variable_buffer_output (o, p2, ++p - p2);
      else if (p >= p2 && (*p == '.'))
        o = variable_buffer_output (o, p2, p - p2);
#ifdef HAVE_DOS_PATHS
      /* Handle the "d:foobar" case */
      else if (p2[0] && p2[1] == ':' && is_dir)
        o = variable_buffer_output (o, p2, 2);
#endif
      else if (is_dir)
#ifdef VMS
        o = variable_buffer_output (o, "[]", 2);
#else
#ifndef _AMIGA
      o = variable_buffer_output (o, "./", 2);
#else
      ; /* Just a nop...  */
#endif /* AMIGA */
#endif /* !VMS */
      else
        /* The entire name is the basename.  */
        o = variable_buffer_output (o, p2, len);

      o = variable_buffer_output (o, " ", 1);
      doneany = 1;
    }

  if (doneany)
    /* Kill last space.  */
    --o;

  return o;
}

static char *
func_addsuffix_addprefix (char *o, char **argv, const char *funcname)
{
  int fixlen = strlen (argv[0]);
  const char *list_iterator = argv[1];
  int is_addprefix = streq (funcname, "addprefix");
  int is_addsuffix = !is_addprefix;

  int doneany = 0;
  const char *p;
  unsigned int len;

  while ((p = find_next_token (&list_iterator, &len)) != 0)
