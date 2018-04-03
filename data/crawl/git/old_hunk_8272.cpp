	}
	trace_argv_printf(argv, argc, "trace: built-in: git");

	return p->fn(argc, argv, prefix);
}

static void handle_internal_command(int argc, const char **argv)