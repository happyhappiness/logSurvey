		close(fd);
		free(new);
		if (wrote != size)
			return error("unable to write file %s", path);
		break;
	case S_IFGITLINK:
		if (to_tempfile)
			return error("cannot create temporary subproject %s", path);
		if (mkdir(path, 0777) < 0)
			return error("cannot create subproject directory %s", path);
		break;
	default:
		return error("unknown file mode for %s in index", path);
	}

	if (state->refresh_cache) {
