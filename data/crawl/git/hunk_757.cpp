 {
 	struct ref_filter *rf = opt->value;
 	unsigned char sha1[20];
+	int no_merged = starts_with(opt->long_name, "no");
 
-	rf->merge = starts_with(opt->long_name, "no")
+	if (rf->merge) {
+		if (no_merged) {
+			return opterror(opt, "is incompatible with --merged", 0);
+		} else {
+			return opterror(opt, "is incompatible with --no-merged", 0);
+		}
+	}
+
+	rf->merge = no_merged
 		? REF_FILTER_MERGED_OMIT
 		: REF_FILTER_MERGED_INCLUDE;
 
