 			i--;
 			if (allow_unmerged)
 				continue;
-			printf("%s: needs merge\n", ce->name);
+			show_file(needs_merge_fmt, ce->name, in_porcelain, &first, header_msg);
 			has_errors = 1;
 			continue;
 		}
