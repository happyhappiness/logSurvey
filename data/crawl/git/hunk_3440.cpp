 	if (!enter_repo(dir, 0))
 		die("'%s' does not appear to be a git repository", dir);
 
-	if (is_repository_shallow() && stateless_rpc)
-		die("attempt to push into a shallow repository");
-
 	git_config(receive_pack_config, NULL);
 
 	if (0 <= transfer_unpack_limit)
