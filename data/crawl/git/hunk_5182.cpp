 	if (!commitable && !in_merge && !allow_empty &&
 	    !(amend && is_a_merge(head_sha1))) {
 		run_status(stdout, index_file, prefix, 0, s);
+		if (amend)
+			fputs(empty_amend_advice, stderr);
 		return 0;
 	}
 