 						: "false");
 				continue;
 			}
+			if (!strcmp(arg, "--is-inside-work-tree")) {
+				printf("%s\n", is_inside_work_tree() ? "true"
+						: "false");
+				continue;
+			}
 			if (!strcmp(arg, "--is-bare-repository")) {
 				printf("%s\n", is_bare_repository() ? "true"
 						: "false");
