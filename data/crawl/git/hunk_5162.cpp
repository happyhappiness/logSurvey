 {
 	unsigned char sha1[20];
 	enum object_type type;
-	void *buf;
+	char *buf;
 	unsigned long size;
+	struct object_context obj_context;
 
-	if (get_sha1(obj_name, sha1))
+	if (get_sha1_with_context(obj_name, sha1, &obj_context))
 		die("Not a valid object name %s", obj_name);
 
 	buf = NULL;
