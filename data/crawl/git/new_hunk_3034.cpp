		const char *name = (const char *)rr->items[i].util;

		if (has_rerere_resolution(name)) {
			if (merge(name, path))
				continue;

			if (rerere_autoupdate)
				string_list_insert(&update, path);
			else
				fprintf(stderr,
					"Resolved '%s' using previous resolution.\n",
					path);
			goto mark_resolved;
		}

		/* Let's see if we have resolved it. */