		*ntr++ = 0; /* now at the beginning of SHA1 */
		if (type != type_from_string(ptr))
			die("object type %s mismatch (%s)", ptr, typename(type));

		path = ntr + 41;  /* at the beginning of name */
		if (line_termination && path[0] == '"') {
			strbuf_reset(&p_uq);
			if (unquote_c_style(&p_uq, path, NULL)) {
				die("invalid quoting");
			}
			path = p_uq.buf;
		}

		append_to_tree(mode, sha1, path);
	}
	strbuf_release(&p_uq);
	strbuf_release(&sb);

	write_tree(sha1);
	puts(sha1_to_hex(sha1));
	exit(0);