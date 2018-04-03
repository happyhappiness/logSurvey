	if (!quiet)
		fprintf(realstdout, "%s\n", filename.buf + outdir_offset);

	if ((rev->diffopt.file = fopen(filename.buf, "w")) == NULL)
		return error(_("Cannot open patch file %s"), filename.buf);

	strbuf_release(&filename);
