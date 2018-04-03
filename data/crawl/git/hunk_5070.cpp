 	add_index_entry(&o->result, new, ADD_CACHE_OK_TO_ADD|ADD_CACHE_OK_TO_REPLACE);
 }
 
+/*
+ * add error messages on path <path>
+ * corresponding to the type <e> with the message <msg>
+ * indicating if it should be display in porcelain or not
+ */
+static int add_rejected_path(struct unpack_trees_options *o,
+			     enum unpack_trees_error_types e,
+			     const char *path)
+{
+	struct rejected_paths_list *newentry;
+	int porcelain = o && (o)->msgs[e];
+	/*
+	 * simply display the given error message if in plumbing mode
+	 */
+	if (!porcelain)
+		o->show_all_errors = 0;
+	if (!o->show_all_errors)
+		return error(ERRORMSG(o, e), path);
+
+	/*
+	 * Otherwise, insert in a list for future display by
+	 * display_error_msgs()
+	 */
+	newentry = xmalloc(sizeof(struct rejected_paths_list));
+	newentry->path = (char *)path;
+	newentry->next = o->unpack_rejects[e];
+	o->unpack_rejects[e] = newentry;
+	return -1;
+}
+
+/*
+ * free all the structures allocated for the error <e>
+ */
+static void free_rejected_paths(struct unpack_trees_options *o,
+				enum unpack_trees_error_types e)
+{
+	while (o->unpack_rejects[e]) {
+		struct rejected_paths_list *del = o->unpack_rejects[e];
+		o->unpack_rejects[e] = o->unpack_rejects[e]->next;
+		free(del);
+	}
+	free(o->unpack_rejects[e]);
+}
+
+/*
+ * display all the error messages stored in a nice way
+ */
+static void display_error_msgs(struct unpack_trees_options *o)
+{
+	int e;
+	int something_displayed = 0;
+	for (e = 0; e < NB_UNPACK_TREES_ERROR_TYPES; e++) {
+		if (o->unpack_rejects[e]) {
+			struct rejected_paths_list *rp;
+			struct strbuf path = STRBUF_INIT;
+			something_displayed = 1;
+			for (rp = o->unpack_rejects[e]; rp; rp = rp->next)
+				strbuf_addf(&path, "\t%s\n", rp->path);
+			error(ERRORMSG(o, e), path.buf);
+			strbuf_release(&path);
+			free_rejected_paths(o, e);
+		}
+	}
+	if (something_displayed)
+		printf("Aborting\n");
+}
+
 /*
  * Unlink the last component and schedule the leading directories for
  * removal, such that empty directories get removed.
