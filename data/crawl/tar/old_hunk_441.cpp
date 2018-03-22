    return value;

 out_of_range:
  ERROR ((0, 0, _("Octal value `%.*s' is out of range for %s"),
	  (int) digs0, where0, type));
  return -1;
}
gid_t
