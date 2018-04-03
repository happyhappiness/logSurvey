 		char *buf, *sp, *eol;
 		size_t len;
 
+		if (filter->with_commit) {
+			struct commit *commit;
+
+			commit = lookup_commit_reference_gently(sha1, 1);
+			if (!commit)
+				return 0;
+			if (!is_descendant_of(commit, filter->with_commit))
+				return 0;
+		}
+
 		if (!filter->lines) {
 			printf("%s\n", refname);
 			return 0;
