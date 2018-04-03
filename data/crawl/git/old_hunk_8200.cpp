			}
		}
		if (!reflogs || reflogs->nr == 0)
			die("No reflogs found for '%s'", branch);
		path_list_insert(branch, &info->complete_reflogs)->util
			= reflogs;
	}
