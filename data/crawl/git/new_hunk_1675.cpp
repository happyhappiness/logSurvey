			warning(_("unknown value '%s' for key '%s'"), value, conf_key);
		break;
	default:
		die("BUG: trailer.c: unhandled type %d", type);
	}
	return 0;
}
