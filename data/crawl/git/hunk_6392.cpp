 	return 0;
 }
 
-static int do_send_pack(int in, int out, struct remote *remote, const char *dest, int nr_refspec, const char **refspec)
+int send_pack(struct send_pack_args *args,
+	      int fd[], struct child_process *conn,
+	      struct ref *remote_refs,
+	      struct extra_have_objects *extra_have)
 {
-	struct ref *ref, *local_refs;
+	int in = fd[0];
+	int out = fd[1];
+	struct ref *ref;
 	int new_refs;
 	int ask_for_status_report = 0;
 	int allow_deleting_refs = 0;
 	int expect_status_report = 0;
-	int flags = MATCH_REFS_NONE;
 	int ret;
-	struct extra_have_objects extra_have;
-
-	memset(&extra_have, 0, sizeof(extra_have));
-	if (args.send_all)
-		flags |= MATCH_REFS_ALL;
-	if (args.send_mirror)
-		flags |= MATCH_REFS_MIRROR;
-
-	/* No funny business with the matcher */
-	remote_tail = get_remote_heads(in, &remote_refs, 0, NULL, REF_NORMAL,
-				       &extra_have);
-	local_refs = get_local_heads();
 
 	/* Does the other end support the reporting? */
 	if (server_supports("report-status"))
 		ask_for_status_report = 1;
 	if (server_supports("delete-refs"))
 		allow_deleting_refs = 1;
 
-	/* match them up */
-	if (!remote_tail)
-		remote_tail = &remote_refs;
-	if (match_refs(local_refs, remote_refs, &remote_tail,
-		       nr_refspec, refspec, flags)) {
-		close(out);
-		return -1;
-	}
-
 	if (!remote_refs) {
 		fprintf(stderr, "No refs in common and none specified; doing nothing.\n"
 			"Perhaps you should specify a branch such as 'master'.\n");
-		close(out);
 		return 0;
 	}
 
