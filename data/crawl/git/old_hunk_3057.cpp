		strbuf_rtrim(&gitdir);
	} else
		strbuf_addstr(&gitdir, get_git_common_dir());
	die(_("'%s' is already checked out at '%s'"), new->name, gitdir.buf);
done:
	strbuf_release(&path);
	strbuf_release(&sb);
