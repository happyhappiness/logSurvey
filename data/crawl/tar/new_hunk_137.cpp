
  t = locate_handler (keyword);
  if (t)
    t->decoder (st, value, size);
  else
    ERROR((0, 0, _("Ignoring unknown extended header keyword `%s'"),
	   keyword));
}

void
