		case DIFF_STATUS_UNMERGED:
		case DIFF_STATUS_MODIFIED:
		case DIFF_STATUS_TYPE_CHANGED:
			if (add_file_to_cache(path, verbose))
				die("updating files failed");
			break;
		case DIFF_STATUS_DELETED:
			remove_file_from_cache(path);
