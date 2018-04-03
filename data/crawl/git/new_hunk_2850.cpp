	default:
		if (!strcmp(arg, "on-demand"))
			return RECURSE_SUBMODULES_ON_DEMAND;
		/* TODO: remove the die for history parsing here */
		die("bad %s argument: %s", opt, arg);
	}
}
