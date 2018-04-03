 			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));
 
 		if (track == BRANCH_TRACK_OVERRIDE)
-			fprintf(stderr, _("The --set-upstream flag is deprecated and will be removed. Consider using --track or --set-upstream-to\n"));
-
-		strbuf_addf(&buf, "refs/remotes/%s", branch->name);
-		remote_tracking = ref_exists(buf.buf);
-		strbuf_release(&buf);
+			die(_("the '--set-upstream' option is no longer supported. Please use '--track' or '--set-upstream-to' instead."));
 
-		branch_existed = ref_exists(branch->refname);
 		create_branch(argv[0], (argc == 2) ? argv[1] : head,
 			      force, reflog, 0, quiet, track);
 
-		/*
-		 * We only show the instructions if the user gave us
-		 * one branch which doesn't exist locally, but is the
-		 * name of a remote-tracking branch.
-		 */
-		if (argc == 1 && track == BRANCH_TRACK_OVERRIDE &&
-		    !branch_existed && remote_tracking) {
-			fprintf(stderr, _("\nIf you wanted to make '%s' track '%s', do this:\n\n"), head, branch->name);
-			fprintf(stderr, "    git branch -d %s\n", branch->name);
-			fprintf(stderr, "    git branch --set-upstream-to %s\n", branch->name);
-		}
-
 	} else
 		usage_with_options(builtin_branch_usage, options);
 
