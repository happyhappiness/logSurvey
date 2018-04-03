 			else if (!strcmp(argv[i], "--help"))
 				usage(hash_object_usage);
 			else if (!strcmp(argv[i], "--stdin")) {
-				hash_stdin(type, write_object);
+				if (hashstdin)
+					die("Multiple --stdin arguments are not supported");
+				hashstdin = 1;
 			}
 			else
 				usage(hash_object_usage);
 		}
 		else {
 			const char *arg = argv[i];
+
+			if (hashstdin) {
+				hash_stdin(type, write_object);
+				hashstdin = 0;
+			}
 			if (0 <= prefix_length)
 				arg = prefix_filename(prefix, prefix_length,
 						      arg);
 			hash_object(arg, type_from_string(type), write_object);
 			no_more_flags = 1;
 		}
 	}
+	if (hashstdin)
+		hash_stdin(type, write_object);
 	return 0;
 }
