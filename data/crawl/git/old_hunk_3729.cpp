	}
	ALLOC_GROW(pathspec, nr + 1, alloc);
	pathspec[nr] = NULL;
	num_ignored = check_ignore(prefix, (const char **)pathspec);
	maybe_flush_or_die(stdout, "attribute to stdout");
	strbuf_release(&buf);
	strbuf_release(&nbuf);
	free(pathspec);
	return num_ignored;
}

int cmd_check_ignore(int argc, const char **argv, const char *prefix)
{
	int num_ignored;

	git_config(git_default_config, NULL);

