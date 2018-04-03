 			}
 			if (quiet)
 				continue;
-			printf("%s: needs update\n", ce->name);
+			printf("%s: %s\n", ce->name, needs_update_message);
 			has_errors = 1;
 			continue;
 		}
