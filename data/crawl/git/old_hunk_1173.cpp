		return !has_sha1_file(sha1);

	case 'w':
		if (!obj_context.path[0])
			die("git cat-file --filters %s: <object> must be "
			    "<sha1:path>", obj_name);

		if (filter_object(obj_context.path, obj_context.mode,
				  sha1, &buf, &size))
			return -1;
		break;

	case 'c':
		if (!obj_context.path[0])
			die("git cat-file --textconv %s: <object> must be <sha1:path>",
			    obj_name);

		if (textconv_object(obj_context.path, obj_context.mode, sha1, 1, &buf, &size))
			break;

	case 'p':
