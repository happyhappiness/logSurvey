		case DIFF_STATUS_TYPE_CHANGED:
			if (add_file_to_index(&the_index, path, data->flags)) {
				if (!(data->flags & ADD_CACHE_IGNORE_ERRORS))
					die("updating files failed");
				data->add_errors++;
			}
			break;
