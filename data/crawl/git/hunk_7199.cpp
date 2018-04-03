 		return 0;
 	}
 
-	type = sha1_object_info(sha1, &size);
+	if (print_contents)
+		contents = read_sha1_file(sha1, &type, &size);
+	else
+		type = sha1_object_info(sha1, &size);
+
 	if (type <= 0)
 		return 1;
 
 	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
+	fflush(stdout);
+
+	if (print_contents) {
+		write_or_die(1, contents, size);
+		printf("\n");
+		fflush(stdout);
+	}
 
 	return 0;
 }
 
-static int batch_objects(void)
+static int batch_objects(int print_contents)
 {
 	struct strbuf buf;
 
 	strbuf_init(&buf, 0);
 	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
-		int error = batch_one_object(buf.buf);
+		int error = batch_one_object(buf.buf, print_contents);
 		if (error)
 			return error;
 	}
 
 	return 0;
 }
 
-static const char cat_file_usage[] = "git-cat-file [ [-t|-s|-e|-p|<type>] <sha1> | --batch-check < <list_of_sha1s> ]";
+static const char cat_file_usage[] = "git-cat-file [ [-t|-s|-e|-p|<type>] <sha1> | [--batch|--batch-check] < <list_of_sha1s> ]";
 
 int cmd_cat_file(int argc, const char **argv, const char *prefix)
 {
-	int i, opt = 0, batch_check = 0;
+	int i, opt = 0, batch = 0, batch_check = 0;
 	const char *exp_type = NULL, *obj_name = NULL;
 
 	git_config(git_default_config);
 
 	for (i = 1; i < argc; ++i) {
 		const char *arg = argv[i];
+		int is_batch = 0, is_batch_check = 0;
+
+		is_batch = !strcmp(arg, "--batch");
+		if (!is_batch)
+			is_batch_check = !strcmp(arg, "--batch-check");
 
-		if (!strcmp(arg, "--batch-check")) {
+		if (is_batch || is_batch_check) {
 			if (opt) {
-				error("git-cat-file: Can't use --batch-check with -%c", opt);
+				error("git-cat-file: Can't use %s with -%c", arg, opt);
 				usage(cat_file_usage);
 			} else if (exp_type) {
-				error("git-cat-file: Can't use --batch-check when a type (\"%s\") is specified", exp_type);
+				error("git-cat-file: Can't use %s when a type (\"%s\") is specified", arg, exp_type);
 				usage(cat_file_usage);
 			} else if (obj_name) {
-				error("git-cat-file: Can't use --batch-check when an object (\"%s\") is specified", obj_name);
+				error("git-cat-file: Can't use %s when an object (\"%s\") is specified", arg, obj_name);
 				usage(cat_file_usage);
 			}
 
-			batch_check = 1;
+			if ((is_batch && batch_check) || (is_batch_check && batch)) {
+				error("git-cat-file: Can't use %s with %s", arg, is_batch ? "--batch-check" : "--batch");
+				usage(cat_file_usage);
+			}
+
+			if (is_batch)
+				batch = 1;
+			else
+				batch_check = 1;
+
 			continue;
 		}
 
 		if (!strcmp(arg, "-t") || !strcmp(arg, "-s") || !strcmp(arg, "-e") || !strcmp(arg, "-p")) {
-			if (batch_check) {
-				error("git-cat-file: Can't use %s with --batch-check", arg);
+			if (batch || batch_check) {
+				error("git-cat-file: Can't use %s with %s", arg, batch ? "--batch" : "--batch-check");
 				usage(cat_file_usage);
 			}
 
