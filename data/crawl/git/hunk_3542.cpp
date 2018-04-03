 				"empty head"));
 		if (squash)
 			die(_("Squash commit into empty head not supported yet"));
-		if (!allow_fast_forward)
+		if (fast_forward == FF_NO)
 			die(_("Non-fast-forward commit does not make sense into "
 			    "an empty head"));
 		remoteheads = collect_parents(head_commit, &head_subsumed, argc, argv);
