		had_nl = 1;
	}

	fputs(prefix, stdout);
	fputs(color, stdout);
	putchar(first);
	fwrite(begin, 1, end-begin, stdout);
	fputs(reset, stdout);
	putchar('\n');
	if (!had_nl)
		fputs("\\ No newline at end of file\n", stdout);
}

static char *output_prefix(struct diff_options *opt)
