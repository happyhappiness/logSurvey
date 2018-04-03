 	rev.diffopt.flags = opts->flags;
 	rev.diffopt.output_format |= DIFF_FORMAT_NAME_STATUS;
 	if (diff_setup_done(&rev.diffopt) < 0)
-		die("diff_setup_done failed");
+		die(_("diff_setup_done failed"));
 	add_pending_object(&rev, head, NULL);
 	run_diff_index(&rev, 0);
 }
