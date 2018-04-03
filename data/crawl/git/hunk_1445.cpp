 			continue;
 		}
 
-		if (get_sha1_tree(arg, tree_sha1))
+		if (get_sha1_tree(arg, tree_oid.hash))
 			die("Not a valid object name %s", arg);
 		if (got_tree)
 			die("Cannot give more than one trees");
