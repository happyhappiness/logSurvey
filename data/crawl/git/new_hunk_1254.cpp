			      : _("Error deleting branch '%s'"),
			      bname.buf);
			ret = 1;
			goto next;
		}
		if (!quiet) {
			printf(remote_branch
