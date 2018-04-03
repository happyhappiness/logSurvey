		}
	}

	if (!match_cnt)
		die("cannot describe '%s'", sha1_to_hex(cmit->object.sha1));

	qsort(all_matches, match_cnt, sizeof(all_matches[0]), compare_pt);

