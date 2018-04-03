 	if (!remote) {
 		if (repo)
 			die("bad repository '%s'", repo);
-		die("No destination configured to push to.");
+		die("No configured push destination.\n"
+		    "Either specify the URL from the command-line or configure a remote repository using\n"
+		    "\n"
+		    "    git remote add <name> <url>\n"
+		    "\n"
+		    "and then push using the remote name\n"
+		    "\n"
+		    "    git push <name>\n");
 	}
 
 	if (remote->mirror)