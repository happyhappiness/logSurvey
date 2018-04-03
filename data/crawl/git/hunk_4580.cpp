 	for (i = 0; i < use_strategies_nr; i++) {
 		int ret;
 		if (i) {
-			printf("Rewinding the tree to pristine...\n");
+			printf(_("Rewinding the tree to pristine...\n"));
 			restore_state();
 		}
 		if (use_strategies_nr != 1)
-			printf("Trying merge strategy %s...\n",
+			printf(_("Trying merge strategy %s...\n"),
 				use_strategies[i]->name);
 		/*
 		 * Remember which strategy left the state in the working
