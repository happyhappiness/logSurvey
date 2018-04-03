	if (!oe)
		die("Unknown mark: %s", command_buf.buf);

	xsnprintf(output, sizeof(output), "%s\n", sha1_to_hex(oe->idx.sha1));
	cat_blob_write(output, GIT_SHA1_HEXSZ + 1);
}

