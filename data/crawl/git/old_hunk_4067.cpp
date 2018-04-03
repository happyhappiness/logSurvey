				errs = error(_("'%s' has changes staged in the index\n"
					     "(use --cached to keep the file, "
					     "or -f to force removal)"), name);
			if (local_changes)
				errs = error(_("'%s' has local modifications\n"
					     "(use --cached to keep the file, "
					     "or -f to force removal)"), name);
		}
	}
	return errs;
