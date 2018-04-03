 {
 	if (n->prio == 2 && !n->tag) {
 		n->tag = lookup_tag(n->sha1);
-		if (!n->tag || parse_tag(n->tag) || !n->tag->tag)
+		if (!n->tag || parse_tag(n->tag))
 			die("annotated tag %s not available", n->path);
+	}
+	if (n->tag && !n->name_checked) {
+		if (!n->tag->tag)
+			die("annotated tag %s has no embedded name", n->path);
 		if (strcmp(n->tag->tag, all ? n->path + 5 : n->path))
 			warning("tag '%s' is really '%s' here", n->tag->tag, n->path);
+		n->name_checked = 1;
 	}
 
 	if (n->tag)
