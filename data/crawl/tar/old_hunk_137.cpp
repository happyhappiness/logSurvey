
  t = locate_handler (keyword);
  if (t)
    t->decoder (st, value);
}

void
