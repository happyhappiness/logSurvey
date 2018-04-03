			printf("%s\n", find_unique_abbrev(sha1, abbrev));
			return;
		}
		die("cannot describe '%s'", sha1_to_hex(sha1));
	}

	qsort(all_matches, match_cnt, sizeof(all_matches[0]), compare_pt);