 	if (amend && initial_commit)
 		die("You have nothing to amend.");
 	if (amend && in_merge)
-		die("You are in the middle of a merger -- cannot amend.");
+		die("You are in the middle of a merge -- cannot amend.");
 
 	if (use_message)
 		f++;
