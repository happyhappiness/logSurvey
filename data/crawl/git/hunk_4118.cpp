 	memset(ids, 0, sizeof(*ids));
 	diff_setup(&ids->diffopts);
 	DIFF_OPT_SET(&ids->diffopts, RECURSIVE);
-	if (diff_setup_done(&ids->diffopts) < 0)
-		return error("diff_setup_done failed");
+	diff_setup_done(&ids->diffopts);
 	return 0;
 }
 
