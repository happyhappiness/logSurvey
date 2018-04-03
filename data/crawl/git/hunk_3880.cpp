 	}
 	if (is_binary) {
 		show_combined_header(elem, num_parent, dense, rev,
-				     mode_differs, 0);
+				     line_prefix, mode_differs, 0);
 		printf("Binary files differ\n");
 		free(result);
 		return;
