    fputs (" private", stdout);
  if (v->fileinfo.filenm)
    printf (_(" (from '%s', line %lu)"),
            v->fileinfo.filenm, v->fileinfo.lineno);
  putchar ('\n');
  fputs (prefix, stdout);

