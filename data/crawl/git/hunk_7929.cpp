 		prune = 0;
 		if (!need_to_gc())
 			return 0;
+		fprintf(stderr, "Packing your repository for optimum "
+			"performance. If you would rather run\n"
+			"\"git gc\" by hand, run \"git config gc.auto 0\" "
+			"to disable automatic cleanup.\n");
 	} else {
 		/*
 		 * Use safer (for shared repos) "-A" option to