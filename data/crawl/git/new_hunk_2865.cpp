		strbuf_rtrim(&gitdir);
	} else
		strbuf_addstr(&gitdir, get_git_common_dir());
	strbuf_strip_suffix(&gitdir, ".git");

	existing = strbuf_detach(&gitdir, NULL);
done:
	strbuf_release(&path);
	strbuf_release(&sb);
	strbuf_release(&gitdir);

	return existing;
}

char *find_shared_symref(const char *symref, const char *target)
{
	struct strbuf path = STRBUF_INIT;
	DIR *dir;
	struct dirent *d;
	char *existing;

	if ((existing = find_linked_symref(symref, target, NULL)))
		return existing;

	strbuf_addf(&path, "%s/worktrees", get_git_common_dir());
	dir = opendir(path.buf);
	strbuf_release(&path);
	if (!dir)
		return NULL;

	while ((d = readdir(dir)) != NULL) {
		if (!strcmp(d->d_name, ".") || !strcmp(d->d_name, ".."))
			continue;
		existing = find_linked_symref(symref, target, d->d_name);
		if (existing)
			goto done;
	}
done:
	closedir(dir);

	return existing;
}

void die_if_checked_out(const char *branch)
{
	char *existing;

	existing = find_shared_symref("HEAD", branch);
	if (existing) {
		skip_prefix(branch, "refs/heads/", &branch);
		die(_("'%s' is already checked out at '%s'"), branch, existing);
	}
}
