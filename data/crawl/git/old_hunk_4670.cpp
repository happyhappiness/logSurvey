	else if (!strcmp(untracked_files_arg, "all"))
		s->show_untracked_files = SHOW_ALL_UNTRACKED_FILES;
	else
		die("Invalid untracked files mode '%s'", untracked_files_arg);
}

static int parse_and_validate_options(int argc, const char *argv[],
