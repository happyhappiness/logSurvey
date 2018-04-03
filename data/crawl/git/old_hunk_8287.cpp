	return strlen(*buf_p);
}

unsigned long pretty_print_commit(enum cmit_fmt fmt,
				  const struct commit *commit,
				  unsigned long len,
