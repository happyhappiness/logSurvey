 	else
 		alternate_shallow_file = NULL;
 	if (get_pack(args, fd, pack_lockfile))
-		die("git fetch-pack: fetch failed.");
+		die(_("git fetch-pack: fetch failed."));
 
  all_done:
 	return ref;
