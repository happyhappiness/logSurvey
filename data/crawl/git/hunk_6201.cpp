 		}
 	}
 
-	return send_pack(&args, dest, remote, nr_heads, heads);
-}
+	conn = git_connect(fd, dest, receivepack, args.verbose ? CONNECT_VERBOSE : 0);
 
-int send_pack(struct send_pack_args *my_args,
-	      const char *dest, struct remote *remote,
-	      int nr_heads, const char **heads)
-{
-	int fd[2], ret;
-	struct child_process *conn;
+	memset(&extra_have, 0, sizeof(extra_have));
+
+	get_remote_heads(fd[0], &remote_refs, 0, NULL, REF_NORMAL,
+			 &extra_have);
 
-	memcpy(&args, my_args, sizeof(args));
+	verify_remote_names(nr_refspecs, refspecs);
 
-	verify_remote_names(nr_heads, heads);
+	local_refs = get_local_heads();
 
-	conn = git_connect(fd, dest, args.receivepack, args.verbose ? CONNECT_VERBOSE : 0);
-	ret = do_send_pack(fd[0], fd[1], remote, dest, nr_heads, heads);
+	flags = MATCH_REFS_NONE;
+
+	if (send_all)
+		flags |= MATCH_REFS_ALL;
+	if (args.send_mirror)
+		flags |= MATCH_REFS_MIRROR;
+
+	/* match them up */
+	remote_tail = &remote_refs;
+	while (*remote_tail)
+		remote_tail = &((*remote_tail)->next);
+	if (match_refs(local_refs, remote_refs, &remote_tail,
+		       nr_refspecs, refspecs, flags)) {
+		return -1;
+	}
+
+	ret = send_pack(&args, fd, conn, remote_refs, &extra_have);
+
+	close(fd[1]);
 	close(fd[0]);
-	/* do_send_pack always closes fd[1] */
+
 	ret |= finish_connect(conn);
-	return !!ret;
+
+	print_push_status(dest, remote_refs);
+
+	if (!args.dry_run && remote) {
+		struct ref *ref;
+		for (ref = remote_refs; ref; ref = ref->next)
+			update_tracking_ref(remote, ref);
+	}
+
+	if (!ret && !refs_pushed(remote_refs))
+		fprintf(stderr, "Everything up-to-date\n");
+
+	return ret;
 }
