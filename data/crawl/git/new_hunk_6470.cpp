		break;
	case 2:
		if (!strcmp(argv[0], "HEAD") &&
		    prefixcmp(argv[1], "refs/"))
			die("Refusing to point HEAD outside of refs/");
		create_symref(argv[0], argv[1], msg);
		break;
	default:
