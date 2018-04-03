		strbuf_rtrim(&gitdir);
	} else
		strbuf_addstr(&gitdir, get_git_common_dir());
	skip_prefix(branch, "refs/heads/", &branch);
	strbuf_strip_suffix(&gitdir, ".git");
	die(_("'%s' is already checked out at '%s'"), branch, gitdir.buf);
done:
	strbuf_release(&path);
	strbuf_release(&sb);
	strbuf_release(&gitdir);
}

void die_if_checked_out(const char *branch)
{
	struct strbuf path = STRBUF_INIT;
	DIR *dir;
	struct dirent *d;

	check_linked_checkout(branch, NULL);

	strbuf_addf(&path, "%s/worktrees", get_git_common_dir());
	dir = opendir(path.buf);
	strbuf_release(&path);
	if (!dir)
		return;

	while ((d = readdir(dir)) != NULL) {
		if (!strcmp(d->d_name, ".") || !strcmp(d->d_name, ".."))
			continue;
		check_linked_checkout(branch, d->d_name);
	}
	closedir(dir);
}
