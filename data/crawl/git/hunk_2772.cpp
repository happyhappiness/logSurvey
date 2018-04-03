 		remote_prefix = "remotes/";
 
 	memset(&array, 0, sizeof(array));
-	if (filter->merge != REF_FILTER_MERGED_NONE)
-		init_revisions(&revs, NULL);
-
-	data.array = &array;
-	data.filter = filter;
-	array.revs = &revs;
-
-	/*
-	 * First we obtain all regular branch refs and if the HEAD is
-	 * detached then we insert that ref to the end of the ref_fist
-	 * so that it can be printed and removed first.
-	 */
-	for_each_rawref(append_ref, &data);
-	if (filter->detached)
-		head_ref(append_ref, &data);
-	/*
-	 * The following implementation is currently duplicated in ref-filter. It
-	 * will eventually be removed when we port branch.c to use ref-filter APIs.
-	 */
-	if (filter->merge != REF_FILTER_MERGED_NONE) {
-		filter->merge_commit->object.flags |= UNINTERESTING;
-		add_pending_object(&revs, &filter->merge_commit->object, "");
-		revs.limited = 1;
-
-		if (prepare_revision_walk(&revs))
-			die(_("revision walk setup failed"));
-
-		for (i = 0; i < array.nr; i++) {
-			struct ref_array_item *item = array.items[i];
-			struct commit *commit = item->commit;
-			int is_merged = !!(commit->object.flags & UNINTERESTING);
-			item->ignore = is_merged != (filter->merge == REF_FILTER_MERGED_INCLUDE);
-		}
 
-		for (i = 0; i < array.nr; i++) {
-			struct ref_array_item *item = array.items[i];
-			clear_commit_marks(item->commit, ALL_REV_FLAGS);
-		}
-		clear_commit_marks(filter->merge_commit, ALL_REV_FLAGS);
-	}
+	verify_ref_format("%(refname)%(symref)");
+	filter_refs(&array, filter, filter->kind | FILTER_REFS_INCLUDE_BROKEN);
 
 	if (filter->verbose)
 		maxwidth = calc_maxwidth(&array, strlen(remote_prefix));
 
-	qsort(array.items, array.nr, sizeof(struct ref_array_item *), ref_cmp);
+	/*
+	 * If no sorting parameter is given then we default to sorting
+	 * by 'refname'. This would give us an alphabetically sorted
+	 * array with the 'HEAD' ref at the beginning followed by
+	 * local branches 'refs/heads/...' and finally remote-tacking
+	 * branches 'refs/remotes/...'.
+	 */
+	if (!sorting)
+		sorting = ref_default_sorting();
+	ref_array_sort(sorting, &array);
 
 	for (i = 0; i < array.nr; i++)
-		print_ref_item(array.items[i], maxwidth, filter, remote_prefix);
+		format_and_print_ref_item(array.items[i], maxwidth, filter, remote_prefix);
 
 	ref_array_clear(&array);
 }
