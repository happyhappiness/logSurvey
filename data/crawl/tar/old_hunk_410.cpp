  if (value <= (negative ? minus_minval : maxval))
    return negative ? -value : value;

 out_of_range:
  if (type)
    ERROR ((0, 0, _("Numeric value `%.*s' is out of range for %s"),
	    (int) digs, where0, type));
  return -1;
}

