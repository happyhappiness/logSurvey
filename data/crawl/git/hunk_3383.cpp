 				continue;
 			}
 			if (!strcmp(arg, "--resolve-git-dir")) {
-				const char *gitdir = resolve_gitdir(argv[i+1]);
+				const char *gitdir = argv[++i];
 				if (!gitdir)
-					die("not a gitdir '%s'", argv[i+1]);
+					die("--resolve-git-dir requires an argument");
+				gitdir = resolve_gitdir(gitdir);
+				if (!gitdir)
+					die("not a gitdir '%s'", argv[i]);
 				puts(gitdir);
 				continue;
 			}