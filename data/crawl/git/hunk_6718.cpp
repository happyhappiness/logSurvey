 		return 0;
 	if (opt->unmatch_name_only) {
 		/* We did not see any hit, so we want to show this */
-		printf("%s\n", name);
+		show_name(opt, name);
 		return 1;
 	}
 