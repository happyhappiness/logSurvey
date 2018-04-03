	return show_ref(&atom->u.refname, ref->refname);
}

/*
 * Parse the object referred by ref, and grab needed value.
 */
static void populate_value(struct ref_array_item *ref)
{
	void *buf;
	struct object *obj;
	int eaten, i;
	unsigned long size;
	const struct object_id *tagged;

	ref->value = xcalloc(used_atom_cnt, sizeof(struct atom_value));
