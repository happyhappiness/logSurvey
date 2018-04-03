 			add_interactive++;
 	}
 	if (add_interactive) {
-		const char *args[] = { "add--interactive", NULL };
-
-		if (add_interactive != 1 || argc != 2)
+		if (argc != 2)
 			die("add --interactive does not take any parameters");
-		execv_git_cmd(args);
-		exit(1);
+		exit(interactive_add());
 	}
 
 	git_config(git_add_config);
