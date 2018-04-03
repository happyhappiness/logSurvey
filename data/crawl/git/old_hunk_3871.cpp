		}
		if (bad) {
			if (verbose) {
				error("garbage found: %.*s/%s",
				      len + 2, path, ent->d_name);
				(*garbage)++;
			}
			continue;
		}
