 	if (full_tree)
 		printf("deleteall\n");
 	log_tree_diff_flush(rev);
+	string_list_clear(paths_of_changed_objects, 0);
 	rev->diffopt.output_format = saved_output_format;
 
 	printf("\n");
