  (void) define_variable ("MFLAGS", 6, flags, o_env, 0);
}

static int printed_version = 0;

/* Print version information.  */

static void
print_version ()
{
  extern char *remote_description;
  char *precede = print_data_base_flag ? "# " : "";

  printf ("%sGNU Make version %s", precede, version_string);
  if (remote_description != 0 && *remote_description != '\0')
    printf ("-%s", remote_description);
