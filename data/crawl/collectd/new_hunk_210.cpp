  for (i = 0; i < ret_values_num; ++i)
    printf ("%s=%e\n", ret_values_names[i], ret_values[i]);
  BAIL_OUT (0);
#undef BAIL_OUT
} /* getval */

static int flush (lcc_connection_t *c, int argc, char **argv)
{
  int timeout = -1;

  lcc_identifier_t *identifiers = NULL;
  int identifiers_num = 0;

  char **plugins = NULL;
  int plugins_num = 0;

  int status;
  int i;

  assert (strcasecmp (argv[0], "flush") == 0);

#define BAIL_OUT(s) \
  do { \
    if (identifiers != NULL) \
      free (identifiers); \
    identifiers_num = 0; \
    if (plugins != NULL) \
      free (plugins); \
    plugins_num = 0; \
    return (s); \
  } while (0)

  for (i = 1; i < argc; ++i) {
    char *key, *value;

