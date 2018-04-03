		if (eon) {
			if (has_attribute(eon + 1, "unchanged")) {
				(*tail)->status |= REF_STATUS_UPTODATE;
				if (read_ref((*tail)->name,
					     (*tail)->old_sha1) < 0)
					die(N_("Could not read ref %s"),
					    (*tail)->name);
			}
		}
		tail = &((*tail)->next);