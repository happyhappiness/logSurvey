		/* non-fatal; follow return path */
		break;
	case READ_GITFILE_ERR_OPEN_FAILED:
		die_errno(_("error opening '%s'"), path);
	case READ_GITFILE_ERR_TOO_LARGE:
		die(_("too large to be a .git file: '%s'"), path);
	case READ_GITFILE_ERR_READ_FAILED:
		die(_("error reading %s"), path);
	case READ_GITFILE_ERR_INVALID_FORMAT:
		die(_("invalid gitfile format: %s"), path);
	case READ_GITFILE_ERR_NO_PATH:
		die(_("no path in gitfile: %s"), path);
	case READ_GITFILE_ERR_NOT_A_REPO:
		die(_("not a git repository: %s"), dir);
	default:
		die("BUG: unknown error code");
	}
