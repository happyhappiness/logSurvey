 		compile_grep_patterns(revs->grep_filter);
 	}
 
+	if (revs->reverse && revs->reflog_info)
+		die("cannot combine --reverse with --walk-reflogs");
+
 	return left;
 }
 