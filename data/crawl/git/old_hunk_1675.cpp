			warning(_("unknown value '%s' for key '%s'"), value, conf_key);
		break;
	default:
		die("internal bug in trailer.c");
	}
	return 0;
}
