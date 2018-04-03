		*mem_usage += sz;
	}
	if (!src->data) {
		src->data = read_sha1_file(src_entry->idx.sha1, &type, &sz);
		if (!src->data)
			die("object %s cannot be read",
			    sha1_to_hex(src_entry->idx.sha1));
