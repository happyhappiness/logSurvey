 
 	if (!ref) {
 		packet_flush(fd[1]);
-		die("no matching remote head");
+		die(_("no matching remote head"));
 	}
 	prepare_shallow_info(&si, shallow);
 	ref_cpy = do_fetch_pack(args, fd, ref, sought, nr_sought,