		case DIFF_STATUS_UNMERGED:
		case DIFF_STATUS_MODIFIED:
		case DIFF_STATUS_TYPE_CHANGED:
			if (add_file_to_cache(path, verbose))
				die("updating files failed");
			break;
		case DIFF_STATUS_DELETED:
			remove_file_from_cache(path);
			if (verbose)
				printf("remove '%s'\n", path);
			break;
		}
	}
}

void add_files_to_cache(int verbose, const char *prefix, const char **pathspec)
{
	struct rev_info rev;
	init_revisions(&rev, prefix);
	setup_revisions(0, NULL, &rev, NULL);
	rev.prune_data = pathspec;
	rev.diffopt.output_format = DIFF_FORMAT_CALLBACK;
	rev.diffopt.format_callback = update_callback;
	rev.diffopt.format_callback_data = &verbose;
	run_diff_files(&rev, DIFF_RACY_IS_MODIFIED);
}

static void refresh(int verbose, const char **pathspec)
