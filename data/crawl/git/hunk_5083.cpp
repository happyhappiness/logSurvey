 		buf = xstrdup(v);
 		argc = split_cmdline(buf, &argv);
 		if (argc < 0)
-			die("Bad branch.%s.mergeoptions string", branch);
+			die("Bad branch.%s.mergeoptions string: %s", branch,
+			    split_cmdline_strerror(argc));
 		argv = xrealloc(argv, sizeof(*argv) * (argc + 2));
 		memmove(argv + 1, argv, sizeof(*argv) * (argc + 1));
 		argc++;
