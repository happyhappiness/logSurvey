		fprintf(o->file, "%s", header.buf);
		strbuf_reset(&header);
		if (DIFF_OPT_TST(o, BINARY))
			emit_binary_diff(o->file, &mf1, &mf2);
		else
			fprintf(o->file, "Binary files %s and %s differ\n",
				lbl[0], lbl[1]);
		o->found_changes = 1;
	}
	else {
