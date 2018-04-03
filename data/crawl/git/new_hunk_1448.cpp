	fp = xfopen(am_path(state, "rewritten"), "r");

	while (!strbuf_getline_lf(&sb, fp)) {
		struct object_id from_obj, to_obj;

		if (sb.len != GIT_SHA1_HEXSZ * 2 + 1) {
			ret = error(invalid_line, sb.buf);
			goto finish;
		}

		if (get_oid_hex(sb.buf, &from_obj)) {
			ret = error(invalid_line, sb.buf);
			goto finish;
		}
