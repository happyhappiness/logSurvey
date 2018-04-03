
/* fatal with dumping core */
void
_debug_trap(char *message)
{
    if (!opt_catch_signals)
	fatal_dump(message);
