	}
	fputc('\n', outfile);

	return PARSE_OPT_HELP;
}

void usage_with_options(const char * const *usagestr,
			const struct option *opts)
{
	usage_with_options_internal(usagestr, opts, 0, 1);
	exit(129);
}

