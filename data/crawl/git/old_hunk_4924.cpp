		close(fd);
		free(new);
		if (wrote != size)
			return error("git checkout-index: unable to write file %s", path);
		break;
	case S_IFGITLINK:
		if (to_tempfile)
			return error("git checkout-index: cannot create temporary subproject %s", path);
		if (mkdir(path, 0777) < 0)
			return error("git checkout-index: cannot create subproject directory %s", path);
		break;
	default:
		return error("git checkout-index: unknown file mode for %s", path);
	}

	if (state->refresh_cache) {
