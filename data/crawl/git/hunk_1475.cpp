 		if (upstream) {
 			struct commit_list *base_list;
 			struct commit *commit;
-			unsigned char sha1[20];
+			struct object_id oid;
 
-			if (get_sha1(upstream, sha1))
+			if (get_oid(upstream, &oid))
 				die(_("Failed to resolve '%s' as a valid ref."), upstream);
-			commit = lookup_commit_or_die(sha1, "upstream base");
+			commit = lookup_commit_or_die(oid.hash, "upstream base");
 			base_list = get_merge_bases_many(commit, total, list);
 			/* There should be one and only one merge base. */
 			if (!base_list || base_list->next)