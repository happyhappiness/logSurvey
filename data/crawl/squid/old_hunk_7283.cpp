	break;
    }
}

int
comm_set_fd_lifetime(int fd, int lifetime)
{
    FD_ENTRY *f;
    debug(5, 3, "comm_set_fd_lifetime: FD %d lft %d\n", fd, lifetime);
    if (fd < 0 || fd > Squid_MaxFD)
	return 0;
    f = &fd_table[fd];
    if (lifetime < 0)
	return f->lifetime = -1;
    if (shutdown_pending || reread_pending) {
	/* don't increase the lifetime if something pending */
	if (f->lifetime > -1 && (f->lifetime - squid_curtime) < lifetime)
	    return f->lifetime;
    }
    return f->lifetime = (int) squid_curtime + lifetime;
}

int
