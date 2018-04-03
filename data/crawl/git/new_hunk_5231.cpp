		fprintf(o->file, "%s", header.buf);
		strbuf_reset(&header);
		if (DIFF_OPT_TST(o, BINARY))
			emit_binary_diff(o->file, &mf1, &mf2, line_prefix);
		else
			fprintf(o->file, "%sBinary files %s and %s differ\n",
				line_prefix, lbl[0], lbl[1]);
		o->found_changes = 1;
	}
	else {
