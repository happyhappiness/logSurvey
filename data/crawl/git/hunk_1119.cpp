 		for_each_ref(append_matching_ref, NULL);
 		if (saved_matches == ref_name_cnt &&
 		    ref_name_cnt < MAX_REVS)
-			error("no matching refs with %s", av);
+			error(_("no matching refs with %s"), av);
 		if (saved_matches + 1 < ref_name_cnt)
 			sort_ref_range(saved_matches, ref_name_cnt);
 		return;
