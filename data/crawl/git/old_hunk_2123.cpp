		name = mkpathdup(fmt, bname.buf);

		if (kinds == FILTER_REFS_BRANCHES) {
			char *worktree = find_shared_symref("HEAD", name);
			if (worktree) {
				error(_("Cannot delete branch '%s' "
					"checked out at '%s'"),
				      bname.buf, worktree);
				free(worktree);
				ret = 1;
				continue;
			}
