 			if (show_only && (remove_directories || matches)) {
 				printf("Would remove %s\n",
 				       directory.buf + prefix_offset);
-			} else if (quiet && (remove_directories || matches)) {
-				remove_dir_recursively(&directory, 0);
 			} else if (remove_directories || matches) {
-				printf("Removing %s\n",
-				       directory.buf + prefix_offset);
-				remove_dir_recursively(&directory, 0);
+				if (!quiet)
+					printf("Removing %s\n",
+					       directory.buf + prefix_offset);
+				if (remove_dir_recursively(&directory, 0) != 0) {
+					warning("failed to remove '%s'",
+						directory.buf + prefix_offset);
+					errors++;
+				}
 			} else if (show_only) {
 				printf("Would not remove %s\n",
 				       directory.buf + prefix_offset);
