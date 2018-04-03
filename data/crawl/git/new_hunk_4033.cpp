			      bname.buf);
			ret = 1;
		} else {
			if (!quiet)
				printf(remote_branch
				       ? _("Deleted remote branch %s (was %s).\n")
				       : _("Deleted branch %s (was %s).\n"),
				       bname.buf,
				       find_unique_abbrev(sha1, DEFAULT_ABBREV));
			delete_branch_config(bname.buf);
		}
	}
