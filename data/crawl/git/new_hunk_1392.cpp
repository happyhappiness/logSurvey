		had_nl = 1;
	}

	fputs(prefix, file);
	fputs(color, file);
	putc(first, file);
	fwrite(begin, 1, end-begin, file);
	fputs(reset, file);
	putc('\n', file);
	if (!had_nl)
		fputs("\\ No newline at end of file\n", file);
}

static char *output_prefix(struct diff_options *opt)
