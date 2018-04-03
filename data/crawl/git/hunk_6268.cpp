 	commit->buffer = NULL;
 }
 
-static void finish_object(struct object_array_entry *p)
+static void finish_object(struct object *obj, const char *name)
 {
-	if (p->item->type == OBJ_BLOB && !has_sha1_file(p->item->sha1))
-		die("missing blob object '%s'", sha1_to_hex(p->item->sha1));
+	if (obj->type == OBJ_BLOB && !has_sha1_file(obj->sha1))
+		die("missing blob object '%s'", sha1_to_hex(obj->sha1));
 }
 
-static void show_object(struct object_array_entry *p)
+static void show_object(struct object *obj, const char *name)
 {
 	/* An object with name "foo\n0000000..." can be used to
 	 * confuse downstream "git pack-objects" very badly.
 	 */
-	const char *ep = strchr(p->name, '\n');
+	const char *ep = strchr(name, '\n');
 
-	finish_object(p);
+	finish_object(obj, name);
 	if (ep) {
-		printf("%s %.*s\n", sha1_to_hex(p->item->sha1),
-		       (int) (ep - p->name),
-		       p->name);
+		printf("%s %.*s\n", sha1_to_hex(obj->sha1),
+		       (int) (ep - name),
+		       name);
 	}
 	else
-		printf("%s %s\n", sha1_to_hex(p->item->sha1), p->name);
+		printf("%s %s\n", sha1_to_hex(obj->sha1), name);
 }
 
 static void show_edge(struct commit *commit)
