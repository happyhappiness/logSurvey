	return final_commit_name;
}

int cmd_blame(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	const char *path;
	struct scoreboard sb;
	struct origin *o;
	struct blame_entry *ent;
	int i, seen_dashdash, unk, opt;
	long bottom, top, lno;
	int output_option = 0;
	int show_stats = 0;
	const char *revs_file = NULL;
	const char *final_commit_name = NULL;
	enum object_type type;
	const char *bottomtop = NULL;
	const char *contents_from = NULL;

	cmd_is_annotate = !strcmp(argv[0], "annotate");

	git_config(git_blame_config, NULL);
	save_commit_buffer = 0;

	opt = 0;
	seen_dashdash = 0;
	for (unk = i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (*arg != '-')
			break;
		else if (!strcmp("-b", arg))
			blank_boundary = 1;
		else if (!strcmp("--root", arg))
			show_root = 1;
		else if (!strcmp("--reverse", arg)) {
			argv[unk++] = "--children";
			reverse = 1;
		}
		else if (!strcmp(arg, "--show-stats"))
			show_stats = 1;
		else if (!strcmp("-c", arg))
			output_option |= OUTPUT_ANNOTATE_COMPAT;
		else if (!strcmp("-t", arg))
			output_option |= OUTPUT_RAW_TIMESTAMP;
		else if (!strcmp("-l", arg))
			output_option |= OUTPUT_LONG_OBJECT_NAME;
		else if (!strcmp("-s", arg))
			output_option |= OUTPUT_NO_AUTHOR;
		else if (!strcmp("-w", arg))
			xdl_opts |= XDF_IGNORE_WHITESPACE;
		else if (!strcmp("-S", arg) && ++i < argc)
			revs_file = argv[i];
		else if (!prefixcmp(arg, "-M")) {
			opt |= PICKAXE_BLAME_MOVE;
			blame_move_score = parse_score(arg+2);
		}
		else if (!prefixcmp(arg, "-C")) {
			/*
			 * -C enables copy from removed files;
			 * -C -C enables copy from existing files, but only
			 *       when blaming a new file;
			 * -C -C -C enables copy from existing files for
			 *          everybody
			 */
			if (opt & PICKAXE_BLAME_COPY_HARDER)
				opt |= PICKAXE_BLAME_COPY_HARDEST;
			if (opt & PICKAXE_BLAME_COPY)
				opt |= PICKAXE_BLAME_COPY_HARDER;
			opt |= PICKAXE_BLAME_COPY | PICKAXE_BLAME_MOVE;
			blame_copy_score = parse_score(arg+2);
		}
		else if (!prefixcmp(arg, "-L")) {
			if (!arg[2]) {
				if (++i >= argc)
					usage(blame_usage);
				arg = argv[i];
			}
			else
				arg += 2;
			if (bottomtop)
				die("More than one '-L n,m' option given");
			bottomtop = arg;
		}
		else if (!strcmp("--contents", arg)) {
			if (++i >= argc)
				usage(blame_usage);
			contents_from = argv[i];
		}
		else if (!strcmp("--incremental", arg))
			incremental = 1;
		else if (!strcmp("--score-debug", arg))
			output_option |= OUTPUT_SHOW_SCORE;
		else if (!strcmp("-f", arg) ||
			 !strcmp("--show-name", arg))
			output_option |= OUTPUT_SHOW_NAME;
		else if (!strcmp("-n", arg) ||
			 !strcmp("--show-number", arg))
			output_option |= OUTPUT_SHOW_NUMBER;
		else if (!strcmp("-p", arg) ||
			 !strcmp("--porcelain", arg))
			output_option |= OUTPUT_PORCELAIN;
		else if (!strcmp("--", arg)) {
			seen_dashdash = 1;
			i++;
