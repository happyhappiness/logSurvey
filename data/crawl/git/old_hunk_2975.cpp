	run_command_v_opt(argv_gc_auto, RUN_GIT_CMD);
}

/**
 * parse_options() callback that validates and sets opt->value to the
 * PATCH_FORMAT_* enum value corresponding to `arg`.
