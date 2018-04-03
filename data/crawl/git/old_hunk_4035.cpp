			continue;
		}

		rev = lookup_commit_reference(sha1);
		if (!rev) {
			error(_("Couldn't look up commit object for '%s'"), name);
			ret = 1;
			continue;
		}

		if (!force && !branch_merged(kinds, bname.buf, rev, head_rev)) {
			error(_("The branch '%s' is not fully merged.\n"
			      "If you are sure you want to delete it, "
			      "run 'git branch -D %s'."), bname.buf, bname.buf);
			ret = 1;
			continue;
		}