 			DIFF_OPT_SET(&diff_opts, RECURSIVE);
 			diff_opts.output_format |= DIFF_FORMAT_CALLBACK;
 			diff_opts.format_callback = submodule_collect_changed_cb;
-			if (diff_setup_done(&diff_opts) < 0)
-				die("diff_setup_done failed");
+			diff_setup_done(&diff_opts);
 			diff_tree_sha1(parent->item->object.sha1, commit->object.sha1, "", &diff_opts);
 			diffcore_std(&diff_opts);
 			diff_flush(&diff_opts);
