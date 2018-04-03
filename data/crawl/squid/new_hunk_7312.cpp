    debug(35, 5, "fqdncache_add_to_hash: name <%s>\n", f->name);
}

static void
fqdncacheAddHostent(fqdncache_entry * f, const struct hostent *hp)
{
    int k;
    f->name_count = 0;
    f->names[f->name_count++] = xstrdup((char *) hp->h_name);
    for (k = 0; hp->h_aliases[k]; k++) {
	f->names[f->name_count++] = xstrdup(hp->h_aliases[k]);
	if (f->name_count == FQDN_MAX_NAMES)
	    break;
    }
}

static fqdncache_entry *
fqdncacheAddNew(const char *name, const struct hostent *hp, fqdncache_status_t status)
{
    fqdncache_entry *f;
    if (fqdncache_get(name))
	fatal_dump("fqdncacheAddNew: somebody adding a duplicate!");
    debug(14, 10, "fqdncacheAddNew: Adding '%s', status=%c\n",
	name,
	fqdncache_status_char[status]);
    f = fqdncache_create(name);
    if (hp)
	fqdncacheAddHostent(f, hp);
    f->status = status;
    f->lastref = squid_curtime;
    return f;
}

/* walks down the pending list, calling handlers */
