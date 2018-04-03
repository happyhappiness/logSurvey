		case 0:
			break;
		case -1:
			die("fork failed: %s", strerror(errno));
		default:
			exit(0);
	}
	if (setsid() == -1)
		die("setsid failed: %s", strerror(errno));
	close(0);
	close(1);
	close(2);
