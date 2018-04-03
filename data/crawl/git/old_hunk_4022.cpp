	}

	if (opt->loginfo && !opt->no_commit_id) {
		/* When showing a verbose header (i.e. log message),
		 * and not in --pretty=oneline format, we would want
		 * an extra newline between the end of log and the
		 * output for readability.
		 */
		show_log(opt);
		if ((opt->diffopt.output_format & ~DIFF_FORMAT_NO_OUTPUT) &&
		    opt->verbose_header &&
		    opt->commit_format != CMIT_FMT_ONELINE) {
			int pch = DIFF_FORMAT_DIFFSTAT | DIFF_FORMAT_PATCH;
			if (opt->diffopt.output_prefix) {
				struct strbuf *msg = NULL;
				msg = opt->diffopt.output_prefix(&opt->diffopt,
					opt->diffopt.output_prefix_data);
				fwrite(msg->buf, msg->len, 1, stdout);
			}
			if (!opt->shown_dashes) {
				if ((pch & opt->diffopt.output_format) == pch)
					printf("---");
				putchar('\n');
			}
		}
	}
	diff_flush(&opt->diffopt);