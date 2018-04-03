	case 'e':
		return !has_sha1_file(sha1);

	case 'c':
		if (!obj_context.path[0])
			die("git cat-file --textconv %s: <object> must be <sha1:path>",
