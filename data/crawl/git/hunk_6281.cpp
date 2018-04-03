 "    --bisect-all"
 ;
 
-static int show_timestamp;
-static int hdr_termination;
-static const char *header_prefix;
-
 static void finish_commit(struct commit *commit, void *data);
 static void show_commit(struct commit *commit, void *data)
 {
-	struct rev_info *revs = data;
+	struct rev_list_info *info = data;
+	struct rev_info *revs = info->revs;
 
 	graph_show_commit(revs->graph);
 
-	if (show_timestamp)
+	if (info->show_timestamp)
 		printf("%lu ", commit->date);
-	if (header_prefix)
-		fputs(header_prefix, stdout);
+	if (info->header_prefix)
+		fputs(info->header_prefix, stdout);
 
 	if (!revs->graph) {
 		if (commit->object.flags & BOUNDARY)
