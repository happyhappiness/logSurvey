		exit(status);
}

static void compile_submodule_options(const struct grep_opt *opt,
				      const char **argv,
				      int cached, int untracked,
				      int opt_exclude, int use_index,
				      int pattern_type_arg)
{
	struct grep_pat *pattern;

	if (recurse_submodules)
		argv_array_push(&submodule_options, "--recurse-submodules");

	if (cached)
		argv_array_push(&submodule_options, "--cached");
	if (!use_index)
		argv_array_push(&submodule_options, "--no-index");
	if (untracked)
		argv_array_push(&submodule_options, "--untracked");
	if (opt_exclude > 0)
		argv_array_push(&submodule_options, "--exclude-standard");

	if (opt->invert)
		argv_array_push(&submodule_options, "-v");
	if (opt->ignore_case)
		argv_array_push(&submodule_options, "-i");
	if (opt->word_regexp)
		argv_array_push(&submodule_options, "-w");
	switch (opt->binary) {
	case GREP_BINARY_NOMATCH:
		argv_array_push(&submodule_options, "-I");
		break;
	case GREP_BINARY_TEXT:
		argv_array_push(&submodule_options, "-a");
		break;
	default:
		break;
	}
	if (opt->allow_textconv)
		argv_array_push(&submodule_options, "--textconv");
	if (opt->max_depth != -1)
		argv_array_pushf(&submodule_options, "--max-depth=%d",
				 opt->max_depth);
	if (opt->linenum)
		argv_array_push(&submodule_options, "-n");
	if (!opt->pathname)
		argv_array_push(&submodule_options, "-h");
	if (!opt->relative)
		argv_array_push(&submodule_options, "--full-name");
	if (opt->name_only)
		argv_array_push(&submodule_options, "-l");
	if (opt->unmatch_name_only)
		argv_array_push(&submodule_options, "-L");
	if (opt->null_following_name)
		argv_array_push(&submodule_options, "-z");
	if (opt->count)
		argv_array_push(&submodule_options, "-c");
	if (opt->file_break)
		argv_array_push(&submodule_options, "--break");
	if (opt->heading)
		argv_array_push(&submodule_options, "--heading");
	if (opt->pre_context)
		argv_array_pushf(&submodule_options, "--before-context=%d",
				 opt->pre_context);
	if (opt->post_context)
		argv_array_pushf(&submodule_options, "--after-context=%d",
				 opt->post_context);
	if (opt->funcname)
		argv_array_push(&submodule_options, "-p");
	if (opt->funcbody)
		argv_array_push(&submodule_options, "-W");
	if (opt->all_match)
		argv_array_push(&submodule_options, "--all-match");
	if (opt->debug)
		argv_array_push(&submodule_options, "--debug");
	if (opt->status_only)
		argv_array_push(&submodule_options, "-q");

	switch (pattern_type_arg) {
	case GREP_PATTERN_TYPE_BRE:
		argv_array_push(&submodule_options, "-G");
		break;
	case GREP_PATTERN_TYPE_ERE:
		argv_array_push(&submodule_options, "-E");
		break;
	case GREP_PATTERN_TYPE_FIXED:
		argv_array_push(&submodule_options, "-F");
		break;
	case GREP_PATTERN_TYPE_PCRE:
		argv_array_push(&submodule_options, "-P");
		break;
	case GREP_PATTERN_TYPE_UNSPECIFIED:
		break;
	default:
		die("BUG: Added a new grep pattern type without updating switch statement");
	}

	for (pattern = opt->pattern_list; pattern != NULL;
	     pattern = pattern->next) {
		switch (pattern->token) {
		case GREP_PATTERN:
			argv_array_pushf(&submodule_options, "-e%s",
					 pattern->pattern);
			break;
		case GREP_AND:
		case GREP_OPEN_PAREN:
		case GREP_CLOSE_PAREN:
		case GREP_NOT:
		case GREP_OR:
			argv_array_push(&submodule_options, pattern->pattern);
			break;
		/* BODY and HEAD are not used by git-grep */
		case GREP_PATTERN_BODY:
		case GREP_PATTERN_HEAD:
			break;
		}
	}

	/*
	 * Limit number of threads for child process to use.
	 * This is to prevent potential fork-bomb behavior of git-grep as each
	 * submodule process has its own thread pool.
	 */
	argv_array_pushf(&submodule_options, "--threads=%d",
			 DIV_ROUND_UP(num_threads, 2));

	/* Add Pathspecs */
	argv_array_push(&submodule_options, "--");
	for (; *argv; argv++)
		argv_array_push(&submodule_options, *argv);
}

/*
 * Launch child process to grep contents of a submodule
 */
static int grep_submodule_launch(struct grep_opt *opt,
				 const struct grep_source *gs)
{
	struct child_process cp = CHILD_PROCESS_INIT;
	int status, i;
	const char *end_of_base;
	const char *name;
	struct strbuf child_output = STRBUF_INIT;

	end_of_base = strchr(gs->name, ':');
	if (gs->identifier && end_of_base)
		name = end_of_base + 1;
	else
		name = gs->name;

	prepare_submodule_repo_env(&cp.env_array);
	argv_array_push(&cp.env_array, GIT_DIR_ENVIRONMENT);

	if (opt->relative && opt->prefix_length)
		argv_array_pushf(&cp.env_array, "%s=%s",
				 GIT_TOPLEVEL_PREFIX_ENVIRONMENT,
				 opt->prefix);

	/* Add super prefix */
	argv_array_pushf(&cp.args, "--super-prefix=%s%s/",
			 super_prefix ? super_prefix : "",
			 name);
	argv_array_push(&cp.args, "grep");

	/*
	 * Add basename of parent project
	 * When performing grep on a tree object the filename is prefixed
	 * with the object's name: 'tree-name:filename'.  In order to
	 * provide uniformity of output we want to pass the name of the
	 * parent project's object name to the submodule so the submodule can
	 * prefix its output with the parent's name and not its own OID.
	 */
	if (gs->identifier && end_of_base)
		argv_array_pushf(&cp.args, "--parent-basename=%.*s",
				 (int) (end_of_base - gs->name),
				 gs->name);

	/* Add options */
	for (i = 0; i < submodule_options.argc; i++) {
		/*
		 * If there is a tree identifier for the submodule, add the
		 * rev after adding the submodule options but before the
		 * pathspecs.  To do this we listen for the '--' and insert the
		 * oid before pushing the '--' onto the child process argv
		 * array.
		 */
		if (gs->identifier &&
		    !strcmp("--", submodule_options.argv[i])) {
			argv_array_push(&cp.args, oid_to_hex(gs->identifier));
		}

		argv_array_push(&cp.args, submodule_options.argv[i]);
	}

	cp.git_cmd = 1;
	cp.dir = gs->path;

	/*
	 * Capture output to output buffer and check the return code from the
	 * child process.  A '0' indicates a hit, a '1' indicates no hit and
	 * anything else is an error.
	 */
	status = capture_command(&cp, &child_output, 0);
	if (status && (status != 1)) {
		/* flush the buffer */
		write_or_die(1, child_output.buf, child_output.len);
		die("process for submodule '%s' failed with exit code: %d",
		    gs->name, status);
	}

	opt->output(opt, child_output.buf, child_output.len);
	strbuf_release(&child_output);
	/* invert the return code to make a hit equal to 1 */
	return !status;
}

/*
 * Prep grep structures for a submodule grep
 * oid: the oid of the submodule or NULL if using the working tree
 * filename: name of the submodule including tree name of parent
 * path: location of the submodule
 */
static int grep_submodule(struct grep_opt *opt, const struct object_id *oid,
			  const char *filename, const char *path)
{
	if (!is_submodule_active(the_repository, path))
		return 0;
	if (!is_submodule_populated_gently(path, NULL)) {
		/*
		 * If searching history, check for the presence of the
		 * submodule's gitdir before skipping the submodule.
		 */
		if (oid) {
			const struct submodule *sub =
					submodule_from_path(null_sha1, path);
			if (sub)
				path = git_path("modules/%s", sub->name);

			if (!(is_directory(path) && is_git_directory(path)))
				return 0;
		} else {
			return 0;
		}
	}

#ifndef NO_PTHREADS
	if (num_threads) {
		add_work(opt, GREP_SOURCE_SUBMODULE, filename, path, oid);
		return 0;
	} else
#endif
	{
		struct grep_source gs;
		int hit;

		grep_source_init(&gs, GREP_SOURCE_SUBMODULE,
				 filename, path, oid);
		hit = grep_submodule_launch(opt, &gs);

		grep_source_clear(&gs);
		return hit;
	}
}

static int grep_cache(struct grep_opt *opt, const struct pathspec *pathspec,
		      int cached)
{
	int hit = 0;
	int nr;
	struct strbuf name = STRBUF_INIT;
	int name_base_len = 0;
	if (super_prefix) {
		name_base_len = strlen(super_prefix);
		strbuf_addstr(&name, super_prefix);
	}

	read_cache();

	for (nr = 0; nr < active_nr; nr++) {
		const struct cache_entry *ce = active_cache[nr];
		strbuf_setlen(&name, name_base_len);
		strbuf_addstr(&name, ce->name);

