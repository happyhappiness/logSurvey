		case DIFF_STATUS_UNMERGED:
		case DIFF_STATUS_MODIFIED:
		case DIFF_STATUS_TYPE_CHANGED:
			if (add_file_to_cache(path, data->flags & ADD_FILES_VERBOSE)) {
				if (!(data->flags & ADD_FILES_IGNORE_ERRORS))
					die("updating files failed");
				data->add_errors++;
			}
			break;
		case DIFF_STATUS_DELETED:
			remove_file_from_cache(path);
			if (data->flags & ADD_FILES_VERBOSE)
				printf("remove '%s'\n", path);
			break;
		}
	}
}

int add_files_to_cache(const char *prefix, const char **pathspec, int flags)
{
	struct update_callback_data data;
	struct rev_info rev;
	init_revisions(&rev, prefix);
	setup_revisions(0, NULL, &rev, NULL);
	rev.prune_data = pathspec;
	rev.diffopt.output_format = DIFF_FORMAT_CALLBACK;
	rev.diffopt.format_callback = update_callback;
	data.flags = flags;
	data.add_errors = 0;
	rev.diffopt.format_callback_data = &data;
	run_diff_files(&rev, DIFF_RACY_IS_MODIFIED);
	return !!data.add_errors;
}

static void refresh(int verbose, const char **pathspec)
