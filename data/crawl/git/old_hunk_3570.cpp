		break;

	case PUSH_DEFAULT_SIMPLE:
		setup_push_upstream(remote, 1);
		break;

	case PUSH_DEFAULT_UPSTREAM:
		setup_push_upstream(remote, 0);
		break;

	case PUSH_DEFAULT_CURRENT:
		branch = branch_get(NULL);
		if (!branch)
			die(_(message_detached_head_die), remote->name);
		add_refspec(branch->name);
		break;

	case PUSH_DEFAULT_NOTHING: