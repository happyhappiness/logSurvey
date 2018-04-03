			show_reflog_message(opt->reflog_info,
				    opt->commit_format == CMIT_FMT_ONELINE,
				    opt->date_mode);
			if (opt->commit_format == CMIT_FMT_ONELINE) {
				printf("%s", sep);
				return;
			}
		}
	}

