	      char *string = alloca (digs + 1);
	      memcpy (string, where0, digs);
	      string[digs] = '\0';
	      if (type)
		ERROR ((0, 0,
			_("Archive signed base-64 string %s is out of %s range"),
			quote (string), type));
