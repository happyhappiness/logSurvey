		int is_partial = len && buf[len-1] != '\n';

		if (fwrite(buf, 1, len, output) != len)
			die_errno("cannot write output");

		len = read_line_with_nul(buf, sizeof(buf), mbox);
		if (len == 0) {
			if (feof(mbox)) {
				status = 1;
				break;
			}
			die_errno("cannot read mbox");
		}
		if (!is_partial && !is_bare && is_from_line(buf, len))
			break; /* done with one message */
