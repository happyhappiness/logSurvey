 			opt->diffopt.stat_sep = buffer;
 		}
 	} else if (opt->commit_format != CMIT_FMT_USERFORMAT) {
-		fputs(diff_get_color(opt->diffopt.color_diff, DIFF_COMMIT),
-		      stdout);
+		fputs(diff_get_color_opt(&opt->diffopt, DIFF_COMMIT), stdout);
 		if (opt->commit_format != CMIT_FMT_ONELINE)
 			fputs("commit ", stdout);
 		if (commit->object.flags & BOUNDARY)
