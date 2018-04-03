 						: "false");
 				continue;
 			}
+			if (!strcmp(arg, "--is-bare-repository")) {
+				printf("%s\n", is_bare_repository() ? "true"
+						: "false");
+				continue;
+			}
 			if (!prefixcmp(arg, "--since=")) {
 				show_datestring("--max-age=", arg+8);
 				continue;
