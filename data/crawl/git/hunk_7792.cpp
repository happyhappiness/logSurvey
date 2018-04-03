 	commit->buffer = NULL;
 }
 
+static void finish_object(struct object_array_entry *p)
+{
+	if (p->item->type == OBJ_BLOB && !has_sha1_file(p->item->sha1))
+		die("missing blob object '%s'", sha1_to_hex(p->item->sha1));
+}
+
 static void show_object(struct object_array_entry *p)
 {
 	/* An object with name "foo\n0000000..." can be used to
 	 * confuse downstream git-pack-objects very badly.
 	 */
 	const char *ep = strchr(p->name, '\n');
 
-	if (p->item->type == OBJ_BLOB && !has_sha1_file(p->item->sha1))
-		die("missing blob object '%s'", sha1_to_hex(p->item->sha1));
-
+	finish_object(p);
 	if (ep) {
 		printf("%s %.*s\n", sha1_to_hex(p->item->sha1),
 		       (int) (ep - p->name),
