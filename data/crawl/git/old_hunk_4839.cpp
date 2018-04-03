		die("Invalid untracked files mode '%s'", untracked_files_arg);
}

static int parse_and_validate_options(int argc, const char *argv[],
				      const char * const usage[],
				      const char *prefix,
