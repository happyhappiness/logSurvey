 			dir = get_ref_dir(dir->entries[pos]);
 			sort_ref_dir(dir);
 			if (do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data)) {
-				error("'%s' exists; cannot create '%s'",
-				      data.conflicting_refname, refname);
+				strbuf_addf(err, "'%s' exists; cannot create '%s'",
+					    data.conflicting_refname, refname);
 				goto cleanup;
 			}
 		}
