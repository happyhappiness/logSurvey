
#if DBRT_DEBUG > 1
		if (first)
			fprintf(stderr, "index %s\n", first);
#endif
		for (i = 0; i < len; i++) {
			if (!posns[i] || posns[i] == df_conflict_list)
				continue;
#if DBRT_DEBUG > 1
			fprintf(stderr, "%d %s\n", i + 1, posns[i]->name);
#endif
			if (!first || entcmp(first, firstdir,
					     posns[i]->name,
