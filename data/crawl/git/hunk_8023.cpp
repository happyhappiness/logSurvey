 			 */
 			fprintf(stderr, "warning: no common commits\n");
 
-	if (get_pack(fd))
+	if (get_pack(fd, pack_lockfile))
 		die("git-fetch-pack: fetch failed.");
 
  all_done:
