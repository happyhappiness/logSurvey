	break;
    }
}
int
commSetTimeout(int fd, int timeout, PF *handler, void *data)
{
    FD_ENTRY *fde;
    debug(5, 3, "commSetTimeout: FD %d timeout %d\n", fd, timeout);
    if (fd < 0 || fd > Squid_MaxFD)
        fatal_dump("commSetTimeout: bad FD");
    fde = &fd_table[fd];
    if (timeout < 0) {
        fde->timeout_handler = NULL;
        fde->timeout_data = NULL;
        return fde->timeout = 0;
    }
    if (shutdown_pending || reread_pending) {
        /* don't increase the timeout if something pending */
        if (fde->timeout > 0 && (int) (fde->timeout - squid_curtime) < timeout)
            return fde->timeout;
    }
    if (handler || data) {
        fde->timeout_handler = handler;
        fde->timeout_data = data;
    } else if (fde->timeout_handler == NULL) {
        debug_trap("commSetTimeout: setting timeout, but no handler");
    }
    return fde->timeout = squid_curtime + (time_t) timeout;
}

int
