 {
 	struct strbuf buf;
 	unsigned char object[20], prev[20];
-	int annotate = 0, sign = 0, force = 0, lines = 0, message = 0;
 	char ref[PATH_MAX];
 	const char *object_ref, *tag;
-	int i;
 	struct ref_lock *lock;
 
+	int annotate = 0, sign = 0, force = 0, lines = 0,
+					delete = 0, verify = 0;
+	char *list = NULL, *msg = NULL, *msgfile = NULL, *keyid = NULL;
+	const char *no_pattern = "NO_PATTERN";
+	struct option options[] = {
+		{ OPTION_STRING, 'l', NULL, &list, "pattern", "list tag names",
+			PARSE_OPT_OPTARG, NULL, (intptr_t) no_pattern },
+		{ OPTION_INTEGER, 'n', NULL, &lines, NULL,
+				"print n lines of each tag message",
+				PARSE_OPT_OPTARG, NULL, 1 },
+		OPT_BOOLEAN('d', NULL, &delete, "delete tags"),
+		OPT_BOOLEAN('v', NULL, &verify, "verify tags"),
+
+		OPT_GROUP("Tag creation options"),
+		OPT_BOOLEAN('a', NULL, &annotate,
+					"annotated tag, needs a message"),
+		OPT_STRING('m', NULL, &msg, "msg", "message for the tag"),
+		OPT_STRING('F', NULL, &msgfile, "file", "message in a file"),
+		OPT_BOOLEAN('s', NULL, &sign, "annotated and GPG-signed tag"),
+		OPT_STRING('u', NULL, &keyid, "key-id",
+					"use another key to sign the tag"),
+		OPT_BOOLEAN('f', NULL, &force, "replace the tag if exists"),
+		OPT_END()
+	};
+
 	git_config(git_tag_config);
-	strbuf_init(&buf, 0);
 
-	for (i = 1; i < argc; i++) {
-		const char *arg = argv[i];
+	argc = parse_options(argc, argv, options, git_tag_usage, 0);
 
-		if (arg[0] != '-')
-			break;
-		if (!strcmp(arg, "-a")) {
-			annotate = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-s")) {
-			annotate = 1;
-			sign = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-f")) {
-			force = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-n")) {
-			if (i + 1 == argc || *argv[i + 1] == '-')
-				/* no argument */
-				lines = 1;
-			else
-				lines = isdigit(*argv[++i]) ?
-					atoi(argv[i]) : 1;
-			continue;
-		}
-		if (!strcmp(arg, "-m")) {
-			annotate = 1;
-			i++;
-			if (i == argc)
-				die("option -m needs an argument.");
-			if (message)
-				die("only one -F or -m option is allowed.");
-			strbuf_addstr(&buf, argv[i]);
-			message = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-F")) {
-			annotate = 1;
-			i++;
-			if (i == argc)
-				die("option -F needs an argument.");
-			if (message)
-				die("only one -F or -m option is allowed.");
-
-			if (!strcmp(argv[i], "-")) {
+	if (list)
+		return list_tags(list == no_pattern ? NULL : list, lines);
+	if (delete)
+		return for_each_tag_name(argv, delete_tag);
+	if (verify)
+		return for_each_tag_name(argv, verify_tag);
+
+	strbuf_init(&buf, 0);
+	if (msg || msgfile) {
+		if (msg && msgfile)
+			die("only one -F or -m option is allowed.");
+		annotate = 1;
+		if (msg)
+			strbuf_addstr(&buf, msg);
+		else {
+			if (!strcmp(msgfile, "-")) {
 				if (strbuf_read(&buf, 0, 1024) < 0)
-					die("cannot read %s", argv[i]);
+					die("cannot read %s", msgfile);
 			} else {
-				if (strbuf_read_file(&buf, argv[i], 1024) < 0)
+				if (strbuf_read_file(&buf, msgfile, 1024) < 0)
 					die("could not open or read '%s': %s",
-						argv[i], strerror(errno));
+						msgfile, strerror(errno));
 			}
-			message = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-u")) {
-			annotate = 1;
-			sign = 1;
-			i++;
-			if (i == argc)
-				die("option -u needs an argument.");
-			if (strlcpy(signingkey, argv[i], sizeof(signingkey))
-							>= sizeof(signingkey))
-				die("argument to option -u too long");
-			continue;
 		}
-		if (!strcmp(arg, "-l"))
-			return list_tags(argv[i + 1], lines);
-		if (!strcmp(arg, "-d"))
-			return for_each_tag_name(argv + i + 1, delete_tag);
-		if (!strcmp(arg, "-v"))
-			return for_each_tag_name(argv + i + 1, verify_tag);
-		usage(builtin_tag_usage);
 	}
 
-	if (i == argc) {
+	if (argc == 0) {
 		if (annotate)
-			usage(builtin_tag_usage);
+			usage_with_options(git_tag_usage, options);
 		return list_tags(NULL, lines);
 	}
-	tag = argv[i++];
+	tag = argv[0];
 
-	object_ref = i < argc ? argv[i] : "HEAD";
-	if (i + 1 < argc)
+	object_ref = argc == 2 ? argv[1] : "HEAD";
+	if (argc > 2)
 		die("too many params");
 
 	if (get_sha1(object_ref, object))
