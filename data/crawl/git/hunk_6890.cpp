 		free(collected.e);
 	}
 
-	while (i < argc) {
-		const char *ref = argv[i++];
+	for (; i < argc; i++) {
+		char *ref;
 		unsigned char sha1[20];
-		if (!resolve_ref(ref, sha1, 1, NULL)) {
-			status |= error("%s points nowhere!", ref);
+		if (!dwim_log(argv[i], strlen(argv[i]), sha1, &ref)) {
+			status |= error("%s points nowhere!", argv[i]);
 			continue;
 		}
 		set_reflog_expiry_param(&cb, explicit_expiry, ref);