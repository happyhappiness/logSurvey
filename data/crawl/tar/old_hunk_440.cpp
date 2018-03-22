
  if (digs != 0 && *where && !ISSPACE (*where))
    {
      ERROR ((0, 0, _("Header contains `%.*s' where octal %s value expected"),
	      (int) digs0, where0, type));
      return -1;
    }

