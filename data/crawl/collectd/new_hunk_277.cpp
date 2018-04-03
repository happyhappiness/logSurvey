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
