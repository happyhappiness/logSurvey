 	for (; argc; argc--, argv++) {
 		int i;
 
-		get_remote_ref_states(*argv, &states, 1);
+		get_remote_ref_states(*argv, &states, GET_REF_STATES);
 
 		if (states.stale.nr) {
 			printf("Pruning %s\n", *argv);
