			logerror("'%s': Non-absolute path denied (base-path active)", dir);
			return NULL;
		}
		snprintf(rpath, PATH_MAX, "%s%s", base_path, dir);
		dir = rpath;
	}
