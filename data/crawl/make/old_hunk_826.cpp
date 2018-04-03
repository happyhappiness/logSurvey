/* Print an error message from errno.  */

void
perror_with_name (str, name)
     const char *str, *name;
{
  error (NILF, _("%s%s: %s"), str, name, strerror (errno));
}
