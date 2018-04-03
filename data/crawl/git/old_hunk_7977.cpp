		fputs(topath[checkout_stage], stdout);

	putchar('\t');
	write_name_quoted("", 0, name + prefix_length,
		line_termination, stdout);
	putchar(line_termination);

	for (i = 0; i < 4; i++) {
		topath[i][0] = 0;
