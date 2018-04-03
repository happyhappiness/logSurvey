			}
		}
		if (!reflogs || reflogs->nr == 0)
			return -1;
		path_list_insert(branch, &info->complete_reflogs)->util
			= reflogs;
	}
