		}
	}

	for (rmp = &ref_map; *rmp; ) {
		if ((*rmp)->peer_ref) {
			int st = check_ref_format((*rmp)->peer_ref->name + 5);
			if (st && st != CHECK_REF_FORMAT_ONELEVEL) {
				struct ref *ignore = *rmp;
				error("* Ignoring funny ref '%s' locally",
				      (*rmp)->peer_ref->name);
				*rmp = (*rmp)->next;
				free(ignore->peer_ref);
				free(ignore);
				continue;
			}
		}
		rmp = &((*rmp)->next);
	}

	if (ref_map)
