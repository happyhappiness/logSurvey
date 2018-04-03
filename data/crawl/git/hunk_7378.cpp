 	return seen_commits;
 }
 
+static void display_name(struct commit_name *n)
+{
+	if (n->prio == 2 && !n->tag) {
+		n->tag = lookup_tag(n->sha1);
+		if (!n->tag || !n->tag->tag)
+			die("annotated tag %s not available", n->path);
+		if (strcmp(n->tag->tag, n->path))
+			warning("tag '%s' is really '%s' here", n->tag->tag, n->path);
+	}
+
+	if (n->tag)
+		printf("%s", n->tag->tag);
+	else
+		printf("%s", n->path);
+}
+
 static void describe(const char *arg, int last_one)
 {
 	unsigned char sha1[20];
