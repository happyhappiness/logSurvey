		if (ret < 0 && errno == ENOTDIR)
			ret = unlink(path.buf);
		if (ret)
			error_errno(_("failed to remove '%s'"), path.buf);
	}
	closedir(dir);
	if (!show_only)