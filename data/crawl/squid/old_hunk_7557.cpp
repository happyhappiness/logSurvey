}

/* fatal with dumping core */
void _debug_trap(message)
     char *message;
{
    if (opt_catch_signals)
	fatal_dump(message);
    _db_print(0, 0, "WARNING: %s\n", message);
}

void sig_child(sig)
     int sig;
{
#ifdef _SQUID_NEXT_
    union wait status;
