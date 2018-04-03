}

void
debug_trap(const char *message) {
    if (!opt_catch_signals)
        fatal_dump(message);

    _db_print("WARNING: %s\n", message);
}

void
sig_child(int sig) {
#ifndef _SQUID_MSWIN_
#ifdef _SQUID_NEXT_
    union wait status;
