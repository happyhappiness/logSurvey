 	if (prepare_revision_walk(&revs))
 		die(_("revision walk setup failed"));
 
+	if (reverse && revs.first_parent_only) {
+		struct commit *c = final_commit;
+
+		sb.revs->children.name = "children";
+		while (c->parents &&
+		       hashcmp(c->object.sha1, sb.final->object.sha1)) {
+			struct commit_list *l = xcalloc(1, sizeof(*l));
+
+			l->item = c;
+			if (add_decoration(&sb.revs->children,
+					   &c->parents->item->object, l))
+				die("BUG: not unique item in first-parent chain");
+			c = c->parents->item;
+		}
+
+		if (hashcmp(c->object.sha1, sb.final->object.sha1))
+			die("--reverse --first-parent together require range along first-parent chain");
+	}
+
 	if (is_null_sha1(sb.final->object.sha1)) {
 		o = sb.final->util;
 		sb.final_buf = xmemdupz(o->file.ptr, o->file.size);
