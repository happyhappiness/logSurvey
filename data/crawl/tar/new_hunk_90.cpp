  if (t)
    t->decoder (st, keyword, value, size);
  else
    WARN((0, 0, _("Ignoring unknown extended header keyword `%s'"),
	 keyword));
}

void
