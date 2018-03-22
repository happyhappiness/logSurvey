  char buf[UINTMAX_STRSIZE_BOUND];
  int e = errno;
  ERROR ((0, e,
	  _("%s: Read error at byte %s, reading %lu bytes"),
	  quotearg_colon (name), STRINGIFY_BIGINT (offset, buf),
	  (unsigned long) size));
}
