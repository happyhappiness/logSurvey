		*mem_usage += sz;
	}
	if (!src->data) {
		read_lock();
		src->data = read_sha1_file(src_entry->idx.sha1, &type, &sz);
		read_unlock();
		if (!src->data)
			die("object %s cannot be read",
			    sha1_to_hex(src_entry->idx.sha1));
