	struct strbuf sb = STRBUF_INIT;
	struct object_id oid;

	fp = xfopen(filename, "r");
	while (strbuf_getline_lf(&sb, fp) != EOF) {
		if (get_oid_hex(sb.buf, &oid))
			continue;  /* invalid line: does not start with SHA1 */
