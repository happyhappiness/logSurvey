 "    --bisect-all"
 ;
 
-static struct rev_info revs;
-
-static int bisect_list;
-static int show_timestamp;
-static int hdr_termination;
-static const char *header_prefix;
-
-static void finish_commit(struct commit *commit);
-static void show_commit(struct commit *commit)
+static void finish_commit(struct commit *commit, void *data);
+static void show_commit(struct commit *commit, void *data)
 {
-	graph_show_commit(revs.graph);
+	struct rev_list_info *info = data;
+	struct rev_info *revs = info->revs;
+
+	graph_show_commit(revs->graph);
 
-	if (show_timestamp)
+	if (info->show_timestamp)
 		printf("%lu ", commit->date);
-	if (header_prefix)
-		fputs(header_prefix, stdout);
+	if (info->header_prefix)
+		fputs(info->header_prefix, stdout);
 
-	if (!revs.graph) {
+	if (!revs->graph) {
 		if (commit->object.flags & BOUNDARY)
 			putchar('-');
 		else if (commit->object.flags & UNINTERESTING)
 			putchar('^');
-		else if (revs.left_right) {
+		else if (revs->left_right) {
 			if (commit->object.flags & SYMMETRIC_LEFT)
 				putchar('<');
 			else
 				putchar('>');
 		}
 	}
-	if (revs.abbrev_commit && revs.abbrev)
-		fputs(find_unique_abbrev(commit->object.sha1, revs.abbrev),
+	if (revs->abbrev_commit && revs->abbrev)
+		fputs(find_unique_abbrev(commit->object.sha1, revs->abbrev),
 		      stdout);
 	else
 		fputs(sha1_to_hex(commit->object.sha1), stdout);
-	if (revs.print_parents) {
+	if (revs->print_parents) {
 		struct commit_list *parents = commit->parents;
 		while (parents) {
 			printf(" %s", sha1_to_hex(parents->item->object.sha1));
 			parents = parents->next;
 		}
 	}
-	if (revs.children.name) {
+	if (revs->children.name) {
 		struct commit_list *children;
 
-		children = lookup_decoration(&revs.children, &commit->object);
+		children = lookup_decoration(&revs->children, &commit->object);
 		while (children) {
 			printf(" %s", sha1_to_hex(children->item->object.sha1));
 			children = children->next;
 		}
 	}
-	show_decorations(&revs, commit);
-	if (revs.commit_format == CMIT_FMT_ONELINE)
+	show_decorations(revs, commit);
+	if (revs->commit_format == CMIT_FMT_ONELINE)
 		putchar(' ');
 	else
 		putchar('\n');
 
-	if (revs.verbose_header && commit->buffer) {
+	if (revs->verbose_header && commit->buffer) {
 		struct strbuf buf = STRBUF_INIT;
-		pretty_print_commit(revs.commit_format, commit,
-				    &buf, revs.abbrev, NULL, NULL,
-				    revs.date_mode, 0);
-		if (revs.graph) {
+		pretty_print_commit(revs->commit_format, commit,
+				    &buf, revs->abbrev, NULL, NULL,
+				    revs->date_mode, 0);
+		if (revs->graph) {
 			if (buf.len) {
-				if (revs.commit_format != CMIT_FMT_ONELINE)
-					graph_show_oneline(revs.graph);
+				if (revs->commit_format != CMIT_FMT_ONELINE)
+					graph_show_oneline(revs->graph);
 
-				graph_show_commit_msg(revs.graph, &buf);
+				graph_show_commit_msg(revs->graph, &buf);
 
 				/*
 				 * Add a newline after the commit message.
