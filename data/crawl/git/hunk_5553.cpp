 			 */
 			warning("no common commits");
 
+	if (args.stateless_rpc)
+		packet_flush(fd[1]);
 	if (get_pack(fd, pack_lockfile))
 		die("git fetch-pack: fetch failed.");
 
