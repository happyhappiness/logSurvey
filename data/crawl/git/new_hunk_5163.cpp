
		/* otherwise just spit out the data */
		break;

	case 'c':
		if (!obj_context.path[0])
			die("git cat-file --textconv %s: <object> must be <sha1:path>",
			    obj_name);

		if (!textconv_object(obj_context.path, sha1, &buf, &size))
			die("git cat-file --textconv: unable to run textconv on %s",
			    obj_name);
		break;

	case 0:
		buf = read_object_with_reference(sha1, exp_type, &size, NULL);
		break;
