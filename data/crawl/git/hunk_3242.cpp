 		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data))
 			return 1;
 
-		report_refname_conflict(data.found, refname);
+		error("'%s' exists; cannot create '%s'", data.found->name, refname);
 		return 0;
 	}
 