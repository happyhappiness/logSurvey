	 * "From " and having something that looks like a date format.
	 */
	for (;;) {
		int is_partial = (buf[len-1] != '\n');

		if (fputs(buf, output) == EOF)
			die("cannot write output");

		if (fgets(buf, sizeof(buf), mbox) == NULL) {
			if (feof(mbox)) {
				status = 1;
				break;
			}
			die("cannot read mbox");
		}
		len = strlen(buf);
		if (!is_partial && !is_bare && is_from_line(buf, len))
			break; /* done with one message */
	}
