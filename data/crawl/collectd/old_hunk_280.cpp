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
