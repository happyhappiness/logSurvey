  }

  return count;
} /* count_chars */

static int flush (const char *address, int argc, char **argv)
{
  lcc_connection_t *connection;

  lcc_identifier_t  ident;
  lcc_identifier_t *identp = NULL;

  char *plugin  = NULL;
  int   timeout = -1;

  int status;
  int i;

  assert (strcasecmp (argv[0], "flush") == 0);

  connection = NULL;
  status = lcc_connect (address, &connection);
  if (status != 0) {
    fprintf (stderr, "ERROR: Failed to connect to daemon at %s: %s.\n",
        address, strerror (errno));
    return (1);
  }

  for (i = 1; i < argc; ++i) {
    char *key, *value;

    key   = argv[i];
    value = strchr (argv[i], (int)'=');

    if (! value) {
      fprintf (stderr, "ERROR: Invalid option ``%s''.\n", argv[i]);
      return (-1);
    }

    *value = '\0';
    ++value;

    if (strcasecmp (key, "timeout") == 0) {
      char *endptr = NULL;

      timeout = strtol (value, &endptr, 0);

      if (endptr == value) {
        fprintf (stderr, "ERROR: Failed to parse timeout as number: %s.\n",
            value);
        return (-1);
      }
      else if ((endptr != NULL) && (*endptr != '\0')) {
        fprintf (stderr, "WARNING: Ignoring trailing garbage after timeout: "
            "%s.\n", endptr);
      }
    }
    else if (strcasecmp (key, "plugin") == 0) {
      plugin = value;
    }
    else if (strcasecmp (key, "identifier") == 0) {
      char hostname[1024];
      char ident_str[1024] = "";
      int  n_slashes;

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

      status = lcc_string_to_identifier (connection, &ident, ident_str);
      if (status != 0) {
        fprintf (stderr, "ERROR: Failed to parse identifier ``%s'': %s.\n",
            ident_str, lcc_strerror(connection));
        LCC_DESTROY (connection);
        return (-1);
      }
      identp = &ident;
    }
  }

  status = lcc_flush (connection, plugin, identp, timeout);
  if (status != 0) {
    fprintf (stderr, "ERROR: Flushing failed: %s.\n",
        lcc_strerror (connection));
    LCC_DESTROY (connection);
    return (-1);
  }

  LCC_DESTROY (connection);

  return 0;
} /* flush */

int main (int argc, char **argv) {
  char address[1024] = "unix:"DEFAULT_SOCK;

  int status;

  while (42) {
    int c;

    c = getopt (argc, argv, "s:h");

    if (c == -1)
      break;
