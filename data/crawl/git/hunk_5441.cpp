 		}
 		else if (!prefixcmp(a, "--max-pack-size="))
 			max_packsize = strtoumax(a + 16, NULL, 0) * 1024 * 1024;
-		else if (!prefixcmp(a, "--depth=")) {
+		else if (!prefixcmp(a, "--big-file-threshold=")) {
+			unsigned long v;
+			if (!git_parse_ulong(a + 21, &v))
+				usage(fast_import_usage);
+			big_file_threshold = v;
+		} else if (!prefixcmp(a, "--depth=")) {
 			max_depth = strtoul(a + 8, NULL, 0);
 			if (max_depth > MAX_DEPTH)
 				die("--depth cannot exceed %u", MAX_DEPTH);
