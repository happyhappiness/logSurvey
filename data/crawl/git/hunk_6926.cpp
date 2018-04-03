 				die("multiple --exec specified");
 			exec = arg + 7;
 			exec_at = i;
-			break;
+		} else if (!strcmp(arg, "--exec")) {
+			if (exec_at)
+				die("multiple --exec specified");
+			if (i + 1 >= argc)
+				die("option --exec requires a value");
+			exec = argv[i + 1];
+			exec_at = i;
+			exec_value_at = ++i;
 		}
 	}
 
 	url = xstrdup(remote);
 	conn = git_connect(fd, url, exec, 0);
 
 	for (i = 1; i < argc; i++) {
-		if (i == exec_at)
+		if (i == exec_at || i == exec_value_at)
 			continue;
 		packet_write(fd[1], "argument %s\n", argv[i]);
 	}
