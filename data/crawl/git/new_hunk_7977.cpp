		fputs(topath[checkout_stage], stdout);

	putchar('\t');
	write_name_quoted(name + prefix_length, stdout, line_termination);

	for (i = 0; i < 4; i++) {
		topath[i][0] = 0;
