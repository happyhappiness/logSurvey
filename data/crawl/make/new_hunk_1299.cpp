perror_with_name (str, name)
     char *str, *name;
{
  error (NILF, "%s%s: %s", str, name, strerror (errno));
}

/* Print an error message from errno and exit.  */
