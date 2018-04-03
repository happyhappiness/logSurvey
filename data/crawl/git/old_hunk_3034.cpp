		const char *name = (const char *)rr->items[i].util;

		if (has_rerere_resolution(name)) {
			if (!merge(name, path)) {
				const char *msg;
				if (rerere_autoupdate) {
					string_list_insert(&update, path);
					msg = "Staged '%s' using previous resolution.\n";
				} else
					msg = "Resolved '%s' using previous resolution.\n";
				fprintf(stderr, msg, path);
				goto mark_resolved;
			}
		}

		/* Let's see if we have resolved it. */