		upstream = argv[1];
		break;
	default:
		usage(cherry_usage);
	}

	init_revisions(&revs, prefix);