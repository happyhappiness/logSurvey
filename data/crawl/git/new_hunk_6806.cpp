	return 1;
}

static const char *find_author_by_nickname(const char *name)
{
	struct rev_info revs;
	struct commit *commit;
	struct strbuf buf = STRBUF_INIT;
	const char *av[20];
	int ac = 0;

	init_revisions(&revs, NULL);
	strbuf_addf(&buf, "--author=%s", name);
	av[++ac] = "--all";
	av[++ac] = "-i";
	av[++ac] = buf.buf;
	av[++ac] = NULL;
	setup_revisions(ac, av, &revs, NULL);
	prepare_revision_walk(&revs);
	commit = get_revision(&revs);
	if (commit) {
		strbuf_release(&buf);
		format_commit_message(commit, "%an <%ae>", &buf, DATE_NORMAL);
		return strbuf_detach(&buf, NULL);
	}
	die("No existing author found with '%s'", name);
}

static int parse_and_validate_options(int argc, const char *argv[],
				      const char * const usage[],
				      const char *prefix)
