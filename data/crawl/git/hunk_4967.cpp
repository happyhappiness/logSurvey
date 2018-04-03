 			die("%s - not something we can merge", argv[0]);
 		update_ref("initial pull", "HEAD", remote_head->sha1, NULL, 0,
 				DIE_ON_ERR);
-		reset_hard(remote_head->sha1, 0);
+		read_empty(remote_head->sha1, 0);
 		return 0;
 	} else {
 		struct strbuf merge_names = STRBUF_INIT;
