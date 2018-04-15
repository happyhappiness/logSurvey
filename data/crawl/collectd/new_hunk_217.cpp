  return count;
} /* count_chars */

static int parse_identifier (lcc_connection_t *c,
    const char *value, lcc_identifier_t *ident)
{
  char hostname[1024];
  char ident_str[1024] = "";
  int  n_slashes;

  int status;

  n_slashes = count_chars (value, '/');
  if (n_slashes == 1) {
    /* The user has omitted the hostname part of the identifier
     * (there is only one '/' in the identifier)
     * Let's add the local hostname */
    if (gethostname (hostname, sizeof (hostname)) != 0) {
      fprintf (stderr, "ERROR: Failed to get local hostname: %s",
          strerror (errno));
      return (-1);
    }
    hostname[sizeof (hostname) - 1] = '\0';

    snprintf (ident_str, sizeof (ident_str), "%s/%s", hostname, value);
    ident_str[sizeof(ident_str) - 1] = '\0';
  }
  else {
    strncpy (ident_str, value, sizeof (ident_str));
    ident_str[sizeof (ident_str) - 1] = '\0';
  }

  status = lcc_string_to_identifier (c, ident, ident_str);
  if (status != 0) {
    fprintf (stderr, "ERROR: Failed to parse identifier ``%s'': %s.\n",
        ident_str, lcc_strerror(c));
    return (-1);
  }
  return (0);
} /* parse_identifier */

static int getval (lcc_connection_t *c, int argc, char **argv)
{
  lcc_identifier_t ident;

  size_t   ret_values_num   = 0;
  gauge_t *ret_values       = NULL;
  char   **ret_values_names = NULL;

  int status;
  size_t i;

  assert (strcasecmp (argv[0], "getval") == 0);

  if (argc != 2) {
    fprintf (stderr, "ERROR: getval: Missing identifier.\n");
    return (-1);
  }

  memset (&ident, 0, sizeof (ident));
  status = parse_identifier (c, argv[1], &ident);
  if (status != 0)
    return (status);

#define BAIL_OUT(s) \
  do { \
    if (ret_values != NULL) \
      free (ret_values); \
    if (ret_values_names != NULL) { \
      for (i = 0; i < ret_values_num; ++i) \
        free (ret_values_names[i]); \
      free (ret_values_names); \
    } \
    ret_values_num = 0; \
    return (s); \
  } while (0)

  status = lcc_getval (c, &ident,
      &ret_values_num, &ret_values, &ret_values_names);
  if (status != 0)
    BAIL_OUT (-1);

  for (i = 0; i < ret_values_num; ++i)
    printf ("%s=%e\n", ret_values_names[i], ret_values[i]);
  BAIL_OUT (0);
} /* getval */

static int flush (lcc_connection_t *c, int argc, char **argv)
{
  lcc_identifier_t  ident;
