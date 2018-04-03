	fputc('\n', rpt);

	fputs("fatal: ", rpt);
	vfprintf(rpt, err, params);
	fputc('\n', rpt);

	fputc('\n', rpt);
