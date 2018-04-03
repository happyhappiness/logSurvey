			i--;
			if (allow_unmerged)
				continue;
			printf("%s: needs merge\n", ce->name);
			has_errors = 1;
			continue;
		}
