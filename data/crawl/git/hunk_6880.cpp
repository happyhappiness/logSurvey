 		if (argc != 1)
 			die("Can merge only exactly one commit into "
 				"empty head");
+		if (squash)
+			die("Squash commit into empty head not supported yet");
+		if (!allow_fast_forward)
+			die("Non-fast-forward commit does not make sense into "
+			    "an empty head");
 		remote_head = peel_to_type(argv[0], 0, NULL, OBJ_COMMIT);
 		if (!remote_head)
 			die("%s - not something we can merge", argv[0]);