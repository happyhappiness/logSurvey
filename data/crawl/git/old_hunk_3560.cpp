	return logmsg_reencode(commit, NULL, out_enc);
}

static int parse_and_validate_options(int argc, const char *argv[],
				      const struct option *options,
				      const char * const usage[],
