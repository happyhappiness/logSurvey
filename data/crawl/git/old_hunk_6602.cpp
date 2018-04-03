		else if (hunk == RR_SIDE_2)
			strbuf_addstr(&two, buf);
		else if (out)
			fputs(buf, out);
		continue;
	bad:
		hunk = 99; /* force error exit */
