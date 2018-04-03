		}

		if (unlink(dest->buf) && errno != ENOENT)
			die_errno("failed to unlink '%s'", dest->buf);
		if (!option_no_hardlinks) {
			if (!link(src->buf, dest->buf))
				continue;
