 	 */
 
 	if (opt->commit_format == CMIT_FMT_EMAIL) {
-		log_write_email_headers(opt, commit, &subject, &extra_headers,
-					&need_8bit_cte);
+		log_write_email_headers(opt, commit, &ctx.subject, &extra_headers,
+					&ctx.need_8bit_cte);
 	} else if (opt->commit_format != CMIT_FMT_USERFORMAT) {
 		fputs(diff_get_color_opt(&opt->diffopt, DIFF_COMMIT), stdout);
 		if (opt->commit_format != CMIT_FMT_ONELINE)
