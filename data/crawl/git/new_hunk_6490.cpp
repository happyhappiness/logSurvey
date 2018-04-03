		if (wrote != size)
			return error("git checkout-index: unable to write file %s", path);
		break;
	case S_IFGITLINK:
		if (to_tempfile)
			return error("git checkout-index: cannot create temporary subproject %s", path);