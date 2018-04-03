 		prune = 0;
 		if (!need_to_gc())
 			return 0;
-		fprintf(stderr, "Packing your repository for optimum "
+		fprintf(stderr, "Auto packing your repository for optimum "
 			"performance. You may also\n"
 			"run \"git gc\" manually. See "
 			"\"git help gc\" for more information.\n");