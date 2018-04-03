 	commit->buffer = NULL;
 }
 
-static void show_object(struct object_array_entry *p)
+static void show_object(struct object *obj, const char *name)
 {
 	/* An object with name "foo\n0000000..." can be used to
 	 * confuse downstream git-pack-objects very badly.
 	 */
-	const char *ep = strchr(p->name, '\n');
+	const char *ep = strchr(name, '\n');
 	if (ep) {
-		fprintf(pack_pipe, "%s %.*s\n", sha1_to_hex(p->item->sha1),
-		       (int) (ep - p->name),
-		       p->name);
+		fprintf(pack_pipe, "%s %.*s\n", sha1_to_hex(obj->sha1),
+		       (int) (ep - name),
+		       name);
 	}
 	else
 		fprintf(pack_pipe, "%s %s\n",
-				sha1_to_hex(p->item->sha1), p->name);
+				sha1_to_hex(obj->sha1), name);
 }
 
 static void show_edge(struct commit *commit)