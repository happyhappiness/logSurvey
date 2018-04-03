 		}
 		else if (!prefixcmp(a, "--max-pack-size="))
 			max_packsize = strtoumax(a + 16, NULL, 0) * 1024 * 1024;
-		else if (!prefixcmp(a, "--depth="))
+		else if (!prefixcmp(a, "--depth=")) {
 			max_depth = strtoul(a + 8, NULL, 0);
+			if (max_depth > MAX_DEPTH)
+				die("--depth cannot exceed %u", MAX_DEPTH);
+		}
 		else if (!prefixcmp(a, "--active-branches="))
 			max_active_branches = strtoul(a + 18, NULL, 0);
 		else if (!prefixcmp(a, "--import-marks="))