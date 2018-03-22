
  t = locate_handler (keyword);
  if (t)
    t->decoder (st, keyword, value, size);
  else
    ERROR((0, 0, _("Ignoring unknown extended header keyword `%s'"),
	   keyword));
