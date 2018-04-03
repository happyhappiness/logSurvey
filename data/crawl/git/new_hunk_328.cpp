	return result;
}

void *fill_tree_descriptor(struct tree_desc *desc, const struct object_id *oid)
{
	unsigned long size = 0;
	void *buf = NULL;

	if (oid) {
		buf = read_object_with_reference(oid->hash, tree_type, &size,
						 NULL);
		if (!buf)
			die("unable to read tree %s", oid_to_hex(oid));
	}
	init_tree_desc(desc, buf, size);
	return buf;
