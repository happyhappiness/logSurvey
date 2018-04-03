	if (S_ISGITLINK(mode))
		allow_missing = 1;


	*ntr++ = 0; /* now at the beginning of SHA1 */

	path = ntr + 41;  /* at the beginning of name */
	if (line_termination && path[0] == '"') {
