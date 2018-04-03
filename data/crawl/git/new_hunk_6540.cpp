		break;

	default:
		die("git cat-file: unknown option: %s", exp_type);
	}

	if (!buf)
