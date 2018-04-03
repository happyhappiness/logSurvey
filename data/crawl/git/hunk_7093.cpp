 			}
 			printf("\n");
 		}
-cleanup_states:
+
+		/* NEEDSWORK: free remote */
+		path_list_clear(&states.new, 0);
+		path_list_clear(&states.stale, 0);
+		path_list_clear(&states.tracked, 0);
+	}
+
+	return result;
+}
+
+static int prune(int argc, const char **argv)
+{
+	int no_query = 0, result = 0;
+	struct option options[] = {
+		OPT_GROUP("prune specific options"),
+		OPT_BOOLEAN('n', NULL, &no_query, "do not query remotes"),
+		OPT_END()
+	};
+	struct ref_states states;
+
+	argc = parse_options(argc, argv, options, builtin_remote_usage, 0);
+
+	if (argc < 1)
+		usage_with_options(builtin_remote_usage, options);
+
+	memset(&states, 0, sizeof(states));
+	for (; argc; argc--, argv++) {
+		int i;
+
+		get_remote_ref_states(*argv, &states, !no_query);
+
+		for (i = 0; i < states.stale.nr; i++) {
+			const char *refname = states.stale.items[i].util;
+			result |= delete_ref(refname, NULL);
+		}
+
 		/* NEEDSWORK: free remote */
 		path_list_clear(&states.new, 0);
 		path_list_clear(&states.stale, 0);
