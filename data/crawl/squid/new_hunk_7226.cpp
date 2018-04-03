    abort();
}

void
debug_trap(const char *message)
{
    if (!opt_catch_signals)
	fatal_dump(message);
    _db_level = 0;
    _db_print("WARNING: %s\n", message);
}

void
