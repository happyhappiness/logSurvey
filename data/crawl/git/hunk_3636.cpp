 
 	if (args->stateless_rpc)
 		packet_flush(fd[1]);
+	if (args->depth > 0)
+		setup_alternate_shallow();
 	if (get_pack(args, fd, pack_lockfile))
 		die("git fetch-pack: fetch failed.");
 
