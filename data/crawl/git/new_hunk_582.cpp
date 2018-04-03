	 */
	if (type <= 0) {
		strbuf_reset(&line);
		strbuf_addf(&line, "%s missing\n", oid_to_hex(oid));
		cat_blob_write(line.buf, line.len);
		strbuf_release(&line);
		free(buf);
		return;
	}
	if (!buf)
		die("Can't read object %s", oid_to_hex(oid));
	if (type != OBJ_BLOB)
		die("Object %s is a %s but a blob was expected.",
		    oid_to_hex(oid), typename(type));
	strbuf_reset(&line);
	strbuf_addf(&line, "%s %s %lu\n", oid_to_hex(oid),
						typename(type), size);
	cat_blob_write(line.buf, line.len);
	strbuf_release(&line);
