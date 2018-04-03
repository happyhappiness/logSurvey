 struct obj_info {
 	off_t offset;
 	unsigned char sha1[20];
+	struct object *obj;
 };
 
+#define FLAG_OPEN (1u<<20)
+#define FLAG_WRITTEN (1u<<21)
+
 static struct obj_info *obj_list;
+unsigned nr_objects;
+
+static void write_cached_object(struct object *obj)
+{
+	unsigned char sha1[20];
+	struct obj_buffer *obj_buf = lookup_object_buffer(obj);
+	if (write_sha1_file(obj_buf->buffer, obj_buf->size, typename(obj->type), sha1) < 0)
+		die("failed to write object %s", sha1_to_hex(obj->sha1));
+	obj->flags |= FLAG_WRITTEN;
+}
+
+static int check_object(struct object *obj, int type, void *data)
+{
+	if (!obj)
+		return 0;
+
+	if (obj->flags & FLAG_WRITTEN)
+		return 1;
+
+	if (type != OBJ_ANY && obj->type != type)
+		die("object type mismatch");
+
+	if (!(obj->flags & FLAG_OPEN)) {
+		unsigned long size;
+		int type = sha1_object_info(obj->sha1, &size);
+		if (type != obj->type || type <= 0)
+			die("object of unexpected type");
+		obj->flags |= FLAG_WRITTEN;
+		return 1;
+	}
+
+	if (fsck_object(obj, 1, fsck_error_function))
+		die("Error in object");
+	if (!fsck_walk(obj, check_object, 0))
+		die("Error on reachable objects of %s", sha1_to_hex(obj->sha1));
+	write_cached_object(obj);
+	return 1;
+}
+
+static void write_rest(void)
+{
+	unsigned i;
+	for (i = 0; i < nr_objects; i++)
+		check_object(obj_list[i].obj, OBJ_ANY, 0);
+}
 
 static void added_object(unsigned nr, enum object_type type,
 			 void *data, unsigned long size);
 
 static void write_object(unsigned nr, enum object_type type,
 			 void *buf, unsigned long size)
 {
-	if (write_sha1_file(buf, size, typename(type), obj_list[nr].sha1) < 0)
-		die("failed to write object");
 	added_object(nr, type, buf, size);
+	if (!strict) {
+		if (write_sha1_file(buf, size, typename(type), obj_list[nr].sha1) < 0)
+			die("failed to write object");
+		free(buf);
+		obj_list[nr].obj = 0;
+	} else if (type == OBJ_BLOB) {
+		struct blob *blob;
+		if (write_sha1_file(buf, size, typename(type), obj_list[nr].sha1) < 0)
+			die("failed to write object");
+		free(buf);
+
+		blob = lookup_blob(obj_list[nr].sha1);
+		if (blob)
+			blob->object.flags |= FLAG_WRITTEN;
+		else
+			die("invalid blob object");
+		obj_list[nr].obj = 0;
+	} else {
+		struct object *obj;
+		int eaten;
+		hash_sha1_file(buf, size, typename(type), obj_list[nr].sha1);
+		obj = parse_object_buffer(obj_list[nr].sha1, type, size, buf, &eaten);
+		if (!obj)
+			die("invalid %s", typename(type));
+		/* buf is stored via add_object_buffer and in obj, if its a tree or commit */
+		add_object_buffer(obj, buf, size);
+		obj->flags |= FLAG_OPEN;
+		obj_list[nr].obj = obj;
+	}
 }
 
 static void resolve_delta(unsigned nr, enum object_type type,
