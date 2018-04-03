 }
 
 /* Per entry merge function */
-static int process_entry(const char *path, struct stage_data *entry,
-			 const char *branch1,
-			 const char *branch2)
+static int process_entry(struct merge_options *o,
+			 const char *path, struct stage_data *entry)
 {
 	/*
 	printf("processing entry, clean cache: %s\n", index_only ? "yes": "no");
