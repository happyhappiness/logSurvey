 		}
 	}
 
-	if (!match_cnt)
-		die("cannot describe '%s'", sha1_to_hex(cmit->object.sha1));
+	if (!match_cnt) {
+		const unsigned char *sha1 = cmit->object.sha1;
+		if (always) {
+			printf("%s\n", find_unique_abbrev(sha1, abbrev));
+			return;
+		}
+		die("cannot describe '%s'", sha1_to_hex(sha1));
+	}
 
 	qsort(all_matches, match_cnt, sizeof(all_matches[0]), compare_pt);
 
