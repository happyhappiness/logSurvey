 		}
 		if (!prefixcmp(arg, "--index-version=")) {
 			char *c;
-			index_default_version = strtoul(arg + 16, &c, 10);
-			if (index_default_version > 2)
+			pack_idx_default_version = strtoul(arg + 16, &c, 10);
+			if (pack_idx_default_version > 2)
 				die("bad %s", arg);
 			if (*c == ',')
-				index_off32_limit = strtoul(c+1, &c, 0);
-			if (*c || index_off32_limit & 0x80000000)
+				pack_idx_off32_limit = strtoul(c+1, &c, 0);
+			if (*c || pack_idx_off32_limit & 0x80000000)
 				die("bad %s", arg);
 			continue;
 		}
