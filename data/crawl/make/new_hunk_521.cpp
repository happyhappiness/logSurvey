  if (v->private_var)
    fputs (" private", stdout);
  if (v->fileinfo.filenm)
    printf (_(" (from '%s', line %lu)"),
            v->fileinfo.filenm, v->fileinfo.lineno);
  putchar ('\n');
  fputs (prefix, stdout);

  /* Is this a 'define'?  */
  if (v->recursive && strchr (v->value, '\n') != 0)
    printf ("define %s\n%s\nendef\n", v->name, v->value);
  else
