 		opts.output_format |=
 			DIFF_FORMAT_SUMMARY | DIFF_FORMAT_DIFFSTAT;
 		opts.detect_rename = DIFF_DETECT_RENAME;
-		if (diff_setup_done(&opts) < 0)
-			die(_("diff_setup_done failed"));
+		diff_setup_done(&opts);
 		diff_tree_sha1(head, new_head, "", &opts);
 		diffcore_std(&opts);
 		diff_flush(&opts);
