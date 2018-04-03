		printf("%s\n", filename.buf + outdir_offset);

	if ((rev->diffopt.file = fopen(filename.buf, "w")) == NULL)
		return error_errno(_("Cannot open patch file %s"),
				   filename.buf);

	strbuf_release(&filename);
	return 0;
