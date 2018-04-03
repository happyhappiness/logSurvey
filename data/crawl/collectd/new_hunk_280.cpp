        ident_str[sizeof (ident_str) - 1] = '\0';
      }

      status = lcc_string_to_identifier (c, &ident, ident_str);
      if (status != 0) {
        fprintf (stderr, "ERROR: Failed to parse identifier ``%s'': %s.\n",
            ident_str, lcc_strerror(c));
        return (-1);
      }
      identp = &ident;
    }
  }

  status = lcc_flush (c, plugin, identp, timeout);
  if (status != 0) {
    fprintf (stderr, "ERROR: Flushing failed: %s.\n",
        lcc_strerror (c));
    return (-1);
  }

  return 0;
} /* flush */

int main (int argc, char **argv) {
  char address[1024] = "unix:"DEFAULT_SOCK;

  lcc_connection_t *c;

  int status;

  while (42) {
