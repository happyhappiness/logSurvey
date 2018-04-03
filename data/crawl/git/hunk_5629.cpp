 	if (!match_cnt) {
 		const unsigned char *sha1 = cmit->object.sha1;
 		if (always) {
-			printf("%s\n", find_unique_abbrev(sha1, abbrev));
+			printf("%s", find_unique_abbrev(sha1, abbrev));
+			if (dirty)
+				printf("%s", dirty);
+			printf("\n");
 			return;
 		}
 		die("cannot describe '%s'", sha1_to_hex(sha1));
