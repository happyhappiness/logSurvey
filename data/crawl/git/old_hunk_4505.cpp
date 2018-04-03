		break;

	case PUSH_DEFAULT_NOTHING:
		die("You didn't specify any refspecs to push, and "
		    "push.default is \"nothing\".");
		break;
	}
}
