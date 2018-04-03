		size = buf.len;
	}
	if (write_in_full(fd, blob, size) != size ||
	    close_tempfile(&temp->tempfile))
		die_errno("unable to write temp-file");
	temp->name = get_tempfile_path(&temp->tempfile);
	oid_to_hex_r(temp->hex, oid);
