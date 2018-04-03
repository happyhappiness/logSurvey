		check_symref(argv[0], quiet);
		break;
	case 2:
		create_symref(argv[0], argv[1], msg);
		break;
	default:
