	default:
		if (!strcmp(arg, "on-demand"))
			return RECURSE_SUBMODULES_ON_DEMAND;
		die("bad %s argument: %s", opt, arg);
	}
}
