		break;

	case PUSH_DEFAULT_SIMPLE:
		if (triangular)
			setup_push_current(remote, branch);
		else
			setup_push_upstream(remote, branch, triangular);
		break;

	case PUSH_DEFAULT_UPSTREAM:
		setup_push_upstream(remote, branch, triangular);
		break;

	case PUSH_DEFAULT_CURRENT:
		setup_push_current(remote, branch);
		break;

	case PUSH_DEFAULT_NOTHING: