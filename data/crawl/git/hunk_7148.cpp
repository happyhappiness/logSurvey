 	return 0;
 }
 
-static const char cat_file_usage[] = "git-cat-file [ [-t|-s|-e|-p|<type>] <sha1> | [--batch|--batch-check] < <list_of_sha1s> ]";
+static const char * const cat_file_usage[] = {
+	"git-cat-file [-t|-s|-e|-p|<type>] <sha1>",
+	"git-cat-file [--batch|--batch-check] < <list_of_sha1s>",
+	NULL
+};
 
 int cmd_cat_file(int argc, const char **argv, const char *prefix)
 {
-	int i, opt = 0, batch = 0, batch_check = 0;
+	int opt = 0, batch = 0;
 	const char *exp_type = NULL, *obj_name = NULL;
 
-	git_config(git_default_config);
-
-	for (i = 1; i < argc; ++i) {
-		const char *arg = argv[i];
-		int is_batch = 0, is_batch_check = 0;
-
-		is_batch = !strcmp(arg, "--batch");
-		if (!is_batch)
-			is_batch_check = !strcmp(arg, "--batch-check");
-
-		if (is_batch || is_batch_check) {
-			if (opt) {
-				error("git-cat-file: Can't use %s with -%c", arg, opt);
-				usage(cat_file_usage);
-			} else if (exp_type) {
-				error("git-cat-file: Can't use %s when a type (\"%s\") is specified", arg, exp_type);
-				usage(cat_file_usage);
-			} else if (obj_name) {
-				error("git-cat-file: Can't use %s when an object (\"%s\") is specified", arg, obj_name);
-				usage(cat_file_usage);
-			}
-
-			if ((is_batch && batch_check) || (is_batch_check && batch)) {
-				error("git-cat-file: Can't use %s with %s", arg, is_batch ? "--batch-check" : "--batch");
-				usage(cat_file_usage);
-			}
-
-			if (is_batch)
-				batch = 1;
-			else
-				batch_check = 1;
+	const struct option options[] = {
+		OPT_GROUP("<type> can be one of: blob, tree, commit, tag"),
+		OPT_SET_INT('t', NULL, &opt, "show object type", 't'),
+		OPT_SET_INT('s', NULL, &opt, "show object size", 's'),
+		OPT_SET_INT('e', NULL, &opt,
+			    "exit with zero when there's no error", 'e'),
+		OPT_SET_INT('p', NULL, &opt, "pretty-print object's content", 'p'),
+		OPT_SET_INT(0, "batch", &batch,
+			    "show info and content of objects feeded on stdin", BATCH),
+		OPT_SET_INT(0, "batch-check", &batch,
+			    "show info about objects feeded on stdin",
+			    BATCH_CHECK),
+		OPT_END()
+	};
 
-			continue;
-		}
-
-		if (!strcmp(arg, "-t") || !strcmp(arg, "-s") || !strcmp(arg, "-e") || !strcmp(arg, "-p")) {
-			if (batch || batch_check) {
-				error("git-cat-file: Can't use %s with %s", arg, batch ? "--batch" : "--batch-check");
-				usage(cat_file_usage);
-			}
-
-			exp_type = arg;
-			opt = exp_type[1];
-			continue;
-		}
-
-		if (arg[0] == '-')
-			usage(cat_file_usage);
-
-		if (!exp_type) {
-			if (batch || batch_check) {
-				error("git-cat-file: Can't specify a type (\"%s\") with %s", arg, batch ? "--batch" : "--batch-check");
-				usage(cat_file_usage);
-			}
-
-			exp_type = arg;
-			continue;
-		}
+	git_config(git_default_config);
 
-		if (obj_name)
-			usage(cat_file_usage);
+	if (argc != 3 && argc != 2)
+		usage_with_options(cat_file_usage, options);
 
-		// We should have hit one of the earlier if (batch || batch_check) cases before
-		// getting here.
-		assert(!batch);
-		assert(!batch_check);
+	argc = parse_options(argc, argv, options, cat_file_usage, 0);
 
-		obj_name = arg;
-		break;
+	if (opt) {
+		if (argc == 1)
+			obj_name = argv[0];
+		else
+			usage_with_options(cat_file_usage, options);
+	}
+	if (!opt && !batch) {
+		if (argc == 2) {
+			exp_type = argv[0];
+			obj_name = argv[1];
+		} else
+			usage_with_options(cat_file_usage, options);
+	}
+	if (batch && (opt || argc)) {
+		usage_with_options(cat_file_usage, options);
 	}
 
-	if (batch || batch_check)
+	if (batch)
 		return batch_objects(batch);
 
-	if (!exp_type || !obj_name)
-		usage(cat_file_usage);
-
 	return cat_one_file(opt, exp_type, obj_name);
 }