	if (!oe)
		die("Unknown mark: %s", command_buf.buf);

	xsnprintf(output, sizeof(output), "%s\n", oid_to_hex(&oe->idx.oid));
	cat_blob_write(output, GIT_SHA1_HEXSZ + 1);
}

