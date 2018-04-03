	if (*sp == '*' && sp < ep)
		sp++; /* deref */
	if (ep <= sp)
		die("malformed field name: %.*s", (int)(ep-atom), atom);

	/* Do we have the atom already used elsewhere? */
	for (i = 0; i < used_atom_cnt; i++) {
