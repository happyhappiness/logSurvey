			printf("%s\n", find_unique_abbrev(sha1, abbrev));
			return;
		}
		if (unannotated_cnt)
			die("No annotated tags can describe '%s'.\n"
			    "However, there were unannotated tags: try --tags.",
			    sha1_to_hex(sha1));
		else
			die("No tags can describe '%s'.\n"
			    "Try --always, or create some tags.",
			    sha1_to_hex(sha1));
	}

	qsort(all_matches, match_cnt, sizeof(all_matches[0]), compare_pt);