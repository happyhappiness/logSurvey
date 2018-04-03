		struct emit_callback ecbdata;
		const struct userdiff_funcname *pe;

		if (!DIFF_XDL_TST(o, WHITESPACE_FLAGS) || must_show_header) {
			fprintf(o->file, "%s", header.buf);
			strbuf_reset(&header);
		}
