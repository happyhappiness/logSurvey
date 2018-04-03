 			}
 			continue;
 		}
-		/* perhaps other parameters later... */
+		if (!strcmp(arg, "--auto")) {
+			if (gc_auto_threshold <= 0)
+				return 0;
+			auto_gc = 1;
+			continue;
+		}
 		break;
 	}
 	if (i != argc)
 		usage(builtin_gc_usage);
 
+	if (auto_gc) {
+		/*
+		 * Auto-gc should be least intrusive as possible.
+		 */
+		prune = 0;
+		for (i = 0; i < ARRAY_SIZE(argv_repack_auto); i++)
+			argv_repack[i] = argv_repack_auto[i];
+		if (!need_to_gc())
+			return 0;
+	}
+
 	if (pack_refs && run_command_v_opt(argv_pack_refs, RUN_GIT_CMD))
 		return error(FAILED_RUN, argv_pack_refs[0]);
 