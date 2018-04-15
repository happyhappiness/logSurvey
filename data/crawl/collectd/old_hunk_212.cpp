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
      int status;

      memset (&ident, 0, sizeof (ident));
      status = parse_identifier (c, value, &ident);
      if (status != 0)
        return (status);
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
#undef BAIL_OUT
} /* flush */

