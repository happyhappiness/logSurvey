 	    (send_all && args.send_mirror))
 		usage(send_pack_usage);
 
-	if (is_repository_shallow() && args.stateless_rpc)
-		die("attempt to push from a shallow repository");
-
 	if (remote_name) {
 		remote = remote_get(remote_name);
 		if (!remote_has_url(remote, dest)) {
