 static uint32_t input_crc32;
 static int input_fd, output_fd, pack_fd;
 
+static int mark_link(struct object *obj, int type, void *data)
+{
+	if (!obj)
+		return -1;
+
+	if (type != OBJ_ANY && obj->type != type)
+		die("object type mismatch at %s", sha1_to_hex(obj->sha1));
+
+	obj->flags |= FLAG_LINK;
+	return 0;
+}
+
+/* The content of each linked object must have been checked
+   or it must be already present in the object database */
+static void check_object(struct object *obj)
+{
+	if (!obj)
+		return;
+
+	if (!(obj->flags & FLAG_LINK))
+		return;
+
+	if (!(obj->flags & FLAG_CHECKED)) {
+		unsigned long size;
+		int type = sha1_object_info(obj->sha1, &size);
+		if (type != obj->type || type <= 0)
+			die("object of unexpected type");
+		obj->flags |= FLAG_CHECKED;
+		return;
+	}
+}
+
+static void check_objects(void)
+{
+	unsigned i, max;
+
+	max = get_max_object_index();
+	for (i = 0; i < max; i++)
+		check_object(get_indexed_object(i));
+}
+
+
 /* Discard current buffer used content. */
 static void flush(void)
 {
