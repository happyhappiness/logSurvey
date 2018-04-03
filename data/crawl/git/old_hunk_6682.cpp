			die("Cannot setup tracking information; starting point is not a branch.");
		break;
	case 1:
		/* Unique completion -- good */
		break;
	default:
		die("Ambiguous object name: '%s'.", start_name);
