		fmt_output_subject(&filename, subject, rev);

	if (!quiet)
		fprintf(realstdout, "%s\n", filename.buf + outdir_offset);

	if (freopen(filename.buf, "w", stdout) == NULL)
		return error(_("Cannot open patch file %s"), filename.buf);

	strbuf_release(&filename);
