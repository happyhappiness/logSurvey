				    &bottom, &top, sb.path))
			usage(blame_usage);
		if (lno < top || ((lno || bottom) && lno < bottom))
			die("file %s has only %lu lines", path, lno);
		if (bottom < 1)
			bottom = 1;
		if (top < 1)
