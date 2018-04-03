
		/* otherwise just spit out the data */
		break;
	case 0:
		buf = read_object_with_reference(sha1, exp_type, &size, NULL);
		break;
