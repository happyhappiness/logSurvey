 			    struct expand_data *data)
 {
 	struct strbuf buf = STRBUF_INIT;
+	struct object_context ctx;
+	int flags = opt->follow_symlinks ? GET_SHA1_FOLLOW_SYMLINKS : 0;
+	enum follow_symlinks_result result;
 
 	if (!obj_name)
 	   return 1;
 
-	if (get_sha1(obj_name, data->sha1)) {
-		printf("%s missing\n", obj_name);
+	result = get_sha1_with_context(obj_name, flags, data->sha1, &ctx);
+	if (result != FOUND) {
+		switch (result) {
+		case MISSING_OBJECT:
+			printf("%s missing\n", obj_name);
+			break;
+		case DANGLING_SYMLINK:
+			printf("dangling %"PRIuMAX"\n%s\n",
+			       (uintmax_t)strlen(obj_name), obj_name);
+			break;
+		case SYMLINK_LOOP:
+			printf("loop %"PRIuMAX"\n%s\n",
+			       (uintmax_t)strlen(obj_name), obj_name);
+			break;
+		case NOT_DIR:
+			printf("notdir %"PRIuMAX"\n%s\n",
+			       (uintmax_t)strlen(obj_name), obj_name);
+			break;
+		default:
+			die("BUG: unknown get_sha1_with_context result %d\n",
+			       result);
+			break;
+		}
+		fflush(stdout);
+		return 0;
+	}
+
+	if (ctx.mode == 0) {
+		printf("symlink %"PRIuMAX"\n%s\n",
+		       (uintmax_t)ctx.symlink_path.len,
+		       ctx.symlink_path.buf);
 		fflush(stdout);
 		return 0;
 	}
