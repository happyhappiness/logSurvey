 			}
 			if (!strcmp(arg, "--show-cdup")) {
 				const char *pfx = prefix;
+				if (!is_inside_work_tree()) {
+					const char *work_tree =
+						get_git_work_tree();
+					if (work_tree)
+						printf("%s\n", work_tree);
+					continue;
+				}
 				while (pfx) {
 					pfx = strchr(pfx, '/');
 					if (pfx) {
