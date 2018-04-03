			logerror("'%s': Non-absolute path denied (base-path active)", dir);
			return NULL;
		}
		rlen = snprintf(rpath, sizeof(rpath), "%s%s", base_path, dir);
		if (rlen >= sizeof(rpath)) {
			logerror("base-path too large: %s", rpath);
			return NULL;
		}
		dir = rpath;
	}
