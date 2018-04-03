 	const char *git_dir;
 	const char *template_dir = NULL;
 	unsigned int flags = 0;
+	int bare_given = 0;
 	int i;
 
 	for (i = 1; i < argc; i++, argv++) {
 		const char *arg = argv[1];
 		if (!prefixcmp(arg, "--template="))
 			template_dir = arg+11;
-		else if (!strcmp(arg, "--bare")) {
-			static char git_dir[PATH_MAX+1];
-			is_bare_repository_cfg = 1;
-			setenv(GIT_DIR_ENVIRONMENT, getcwd(git_dir,
-						sizeof(git_dir)), 0);
-		} else if (!strcmp(arg, "--shared"))
+		else if (!strcmp(arg, "--bare"))
+			bare_given = is_bare_repository_cfg = 1;
+		else if (!strcmp(arg, "--shared"))
 			init_shared_repository = PERM_GROUP;
 		else if (!prefixcmp(arg, "--shared="))
 			init_shared_repository = git_config_perm("arg", arg+9);
 		else if (!strcmp(arg, "-q") || !strcmp(arg, "--quiet"))
 			flags |= INIT_DB_QUIET;
-		else
+		else if (arg[0] == '-')
 			usage(init_db_usage);
+		else
+			break;
 	}
 
+	if (i == argc - 1) {
+		int mkdir_tried = 0;
+	retry:
+		if (chdir(argv[1]) < 0) {
+			if (!mkdir_tried) {
+				int saved;
+				/*
+				 * At this point we haven't read any configuration,
+				 * and we know shared_repository should always be 0;
+				 * but just in case we play safe.
+				 */
+				saved = shared_repository;
+				shared_repository = 0;
+				switch (safe_create_leading_directories_const(argv[1])) {
+				case -3:
+					errno = EEXIST;
+					/* fallthru */
+				case -1:
+					die_errno("cannot mkdir %s", argv[1]);
+					break;
+				default:
+					break;
+				}
+				shared_repository = saved;
+				if (mkdir(argv[1], 0777) < 0)
+					die_errno("cannot mkdir %s", argv[1]);
+				mkdir_tried = 1;
+				goto retry;
+			}
+			die_errno("cannot chdir to %s", argv[1]);
+		}
+	} else if (i < argc - 1) {
+		usage(init_db_usage);
+	}
+	if (bare_given == 1) {
+		static char git_dir[PATH_MAX+1];
+
+		setenv(GIT_DIR_ENVIRONMENT,
+			getcwd(git_dir, sizeof(git_dir)), 0);
+	}
 	if (init_shared_repository != -1)
 		shared_repository = init_shared_repository;
 
