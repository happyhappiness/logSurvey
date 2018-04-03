 			usage(ls_remote_usage);
 		}
 		dest = arg;
+		i++;
 		break;
 	}
 
 	if (!dest)
 		usage(ls_remote_usage);
-	pattern = argv + i + 1;
+
+	if (argv[i]) {
+		int j;
+		pattern = xcalloc(sizeof(const char *), argc - i + 1);
+		for (j = i; j < argc; j++) {
+			int len = strlen(argv[j]);
+			char *p = xmalloc(len + 3);
+			sprintf(p, "*/%s", argv[j]);
+			pattern[j - i] = p;
+		}
+	}
 	remote = nongit ? NULL : remote_get(dest);
 	if (remote && !remote->url_nr)
 		die("remote %s has no configured URL", dest);