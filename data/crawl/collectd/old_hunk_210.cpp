  for (i = 0; i < ret_values_num; ++i)
    printf ("%s=%e\n", ret_values_names[i], ret_values[i]);
  BAIL_OUT (0);
} /* getval */

static int flush (lcc_connection_t *c, int argc, char **argv)
{
  lcc_identifier_t  ident;
  lcc_identifier_t *identp = NULL;

  char *plugin  = NULL;
  int   timeout = -1;

  int status;
  int i;

  assert (strcasecmp (argv[0], "flush") == 0);

  for (i = 1; i < argc; ++i) {
    char *key, *value;

