	    break;
	}
	*t = '\0';
	debug(0, 0) ("asnLoadRead: AS# %d '%s'\n", p->as, s);
	s = t + 1;
	while (*s && isspace(*s))
	    s++;
    }
    if (*s) {
	/* expect more */
	debug(0, 0) ("asnLoadRead: AS# %d expecting more\n", p->as);
	xstrncpy(p->buf, s, p->bufsz);
	p->offset = strlen(p->buf);
	debug(0, 0) ("asnLoadRead: p->buf = '%s'\n", p->buf);
    } else {
	p->offset = 0;
    }
    commSetSelect(fd, COMM_SELECT_READ, asnLoadRead, p, Config.Timeout.read);
}
