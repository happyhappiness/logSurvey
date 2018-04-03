	  else
	    printf ("%s[%u]: ", program, makelevel);
	}
      printf (s1, s2, s3, s4, s5, s6);
      putchar ('\n');
    }

  fflush (stdout);
}

/* Print an error message and exit.  */

/* VARARGS1 */
void
fatal (s1, s2, s3, s4, s5, s6)
     char *s1, *s2, *s3, *s4, *s5, *s6;
{
  log_working_directory (1);

  if (makelevel == 0)
    fprintf (stderr, "%s: *** ", program);
  else
    fprintf (stderr, "%s[%u]: *** ", program, makelevel);
  fprintf (stderr, s1, s2, s3, s4, s5, s6);
  fputs (".  Stop.\n", stderr);

  die (2);
}

/* Print error message.  `s1' is printf control string, `s2' is arg for it. */

/* VARARGS1 */

void
error (s1, s2, s3, s4, s5, s6)
     char *s1, *s2, *s3, *s4, *s5, *s6;
{
  log_working_directory (1);

  if (makelevel == 0)
    fprintf (stderr, "%s: ", program);
  else
    fprintf (stderr, "%s[%u]: ", program, makelevel);
  fprintf (stderr, s1, s2, s3, s4, s5, s6);
  putc ('\n', stderr);
  fflush (stderr);
}

void
makefile_error (file, lineno, s1, s2, s3, s4, s5, s6)
     char *file;
     unsigned int lineno;
     char *s1, *s2, *s3, *s4, *s5, *s6;
{
  log_working_directory (1);

  fprintf (stderr, "%s:%u: ", file, lineno);
  fprintf (stderr, s1, s2, s3, s4, s5, s6);
  putc ('\n', stderr);
  fflush (stderr);
}

void
makefile_fatal (file, lineno, s1, s2, s3, s4, s5, s6)
     char *file;
     unsigned int lineno;
     char *s1, *s2, *s3, *s4, *s5, *s6;
{
  if (!file)
    fatal(s1, s2, s3, s4, s5, s6);

  log_working_directory (1);

  fprintf (stderr, "%s:%u: *** ", file, lineno);
  fprintf (stderr, s1, s2, s3, s4, s5, s6);
  fputs (".  Stop.\n", stderr);

  die (2);
