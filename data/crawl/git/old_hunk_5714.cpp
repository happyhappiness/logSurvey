			}
			if (quiet)
				continue;
			printf("%s: %s\n", ce->name, needs_update_message);
			has_errors = 1;
			continue;
		}
