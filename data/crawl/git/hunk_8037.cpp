 	}
 }
 
-static int do_push(const char *repo)
+static int do_push(const char *repo, int flags)
 {
 	int i, errs;
-	int common_argc;
-	const char **argv;
-	int argc;
 	struct remote *remote = remote_get(repo);
 
 	if (!remote)
 		die("bad repository '%s'", repo);
 
-	if (remote->receivepack) {
-		char *rp = xmalloc(strlen(remote->receivepack) + 16);
-		sprintf(rp, "--receive-pack=%s", remote->receivepack);
-		receivepack = rp;
-	}
 	if (!refspec && !all && remote->push_refspec_nr) {
 		refspec = remote->push_refspec;
 		refspec_nr = remote->push_refspec_nr;
 	}
-
-	argv = xmalloc((refspec_nr + 10) * sizeof(char *));
-	argv[0] = "dummy-send-pack";
-	argc = 1;
-	if (all)
-		argv[argc++] = "--all";
-	if (force)
-		argv[argc++] = "--force";
-	if (receivepack)
-		argv[argc++] = receivepack;
-	common_argc = argc;
-
 	errs = 0;
 	for (i = 0; i < remote->uri_nr; i++) {
+		struct transport *transport =
+			transport_get(remote, remote->uri[i], 0);
 		int err;
-		int dest_argc = common_argc;
-		int dest_refspec_nr = refspec_nr;
-		const char **dest_refspec = refspec;
-		const char *dest = remote->uri[i];
-		const char *sender = "send-pack";
-		if (!prefixcmp(dest, "http://") ||
-		    !prefixcmp(dest, "https://"))
-			sender = "http-push";
-		else {
-			char *rem = xmalloc(strlen(remote->name) + 10);
-			sprintf(rem, "--remote=%s", remote->name);
-			argv[dest_argc++] = rem;
-			if (thin)
-				argv[dest_argc++] = "--thin";
-		}
-		argv[0] = sender;
-		argv[dest_argc++] = dest;
-		while (dest_refspec_nr--)
-			argv[dest_argc++] = *dest_refspec++;
-		argv[dest_argc] = NULL;
+		if (receivepack)
+			transport_set_option(transport,
+					     TRANS_OPT_RECEIVEPACK, receivepack);
+		if (thin)
+			transport_set_option(transport, TRANS_OPT_THIN, "yes");
+
 		if (verbose)
-			fprintf(stderr, "Pushing to %s\n", dest);
-		err = run_command_v_opt(argv, RUN_GIT_CMD);
+			fprintf(stderr, "Pushing to %s\n", remote->uri[i]);
+		err = transport_push(transport, refspec_nr, refspec, flags);
+		err |= transport_disconnect(transport);
+
 		if (!err)
 			continue;
 
 		error("failed to push to '%s'", remote->uri[i]);
-		switch (err) {
-		case -ERR_RUN_COMMAND_FORK:
-			error("unable to fork for %s", sender);
-		case -ERR_RUN_COMMAND_EXEC:
-			error("unable to exec %s", sender);
-			break;
-		case -ERR_RUN_COMMAND_WAITPID:
-		case -ERR_RUN_COMMAND_WAITPID_WRONG_PID:
-		case -ERR_RUN_COMMAND_WAITPID_SIGNAL:
-		case -ERR_RUN_COMMAND_WAITPID_NOEXIT:
-			error("%s died with strange error", sender);
-		}
 		errs++;
 	}
 	return !!errs;
