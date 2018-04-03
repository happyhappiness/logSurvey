 	opts.rename_score = o->rename_score;
 	opts.show_rename_progress = o->show_rename_progress;
 	opts.output_format = DIFF_FORMAT_NO_OUTPUT;
-	if (diff_setup_done(&opts) < 0)
-		die(_("diff setup failed"));
+	diff_setup_done(&opts);
 	diff_tree_sha1(o_tree->object.sha1, tree->object.sha1, "", &opts);
 	diffcore_std(&opts);
 	if (opts.needed_rename_limit > o->needed_rename_limit)
