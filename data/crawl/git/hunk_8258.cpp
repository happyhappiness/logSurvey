 		git_config_set("receive.denyNonFastforwards", "true");
 	}
 
-	printf("%s%s Git repository in %s/\n",
-		reinit ? "Reinitialized existing" : "Initialized empty",
-		shared_repository ? " shared" : "",
-		git_dir);
+	if (!quiet)
+		printf("%s%s Git repository in %s/\n",
+		       reinit ? "Reinitialized existing" : "Initialized empty",
+		       shared_repository ? " shared" : "",
+		       git_dir);
 
 	return 0;
 }