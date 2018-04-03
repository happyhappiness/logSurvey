		break;

	default:
		die("git cat-file: unknown option: %s\n", exp_type);
	}

	if (!buf)
		die("git cat-file %s: bad file", obj_name);

	write_or_die(1, buf, size);
	return 0;
