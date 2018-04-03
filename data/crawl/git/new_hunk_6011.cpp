
	ref->value = xcalloc(sizeof(struct atom_value), used_atom_cnt);

	/* Fill in specials first */
	for (i = 0; i < used_atom_cnt; i++) {
		const char *name = used_atom[i];
