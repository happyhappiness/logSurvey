 			}
 			if (quiet)
 				continue;
-			printf("%s: %s\n", ce->name, needs_update_message);
+			show_file(needs_update_fmt, ce->name, in_porcelain, &first, header_msg);
 			has_errors = 1;
 			continue;
 		}
