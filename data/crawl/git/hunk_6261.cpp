 			string_list_insert(path, rr)->util = hex;
 			if (mkdir(git_path("rr-cache/%s", hex), 0755))
 				continue;
-			handle_file(path, NULL, rr_path(hex, "preimage"));
+			handle_file(path, NULL, rerere_path(hex, "preimage"));
 			fprintf(stderr, "Recorded preimage for '%s'\n", path);
 		}
 	}
