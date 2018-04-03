 		if (diff_use_color_default > 0)
 			DIFF_OPT_SET(&opts, COLOR_DIFF);
 		if (diff_setup_done(&opts) < 0)
-			die("diff_setup_done failed");
+			die(_("diff_setup_done failed"));
 		diff_tree_sha1(head, new_head, "", &opts);
 		diffcore_std(&opts);
 		diff_flush(&opts);
