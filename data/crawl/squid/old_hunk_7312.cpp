    debug(35, 5, "fqdncache_add_to_hash: name <%s>\n", f->name);
}


static void
fqdncache_add(const char *name, fqdncache_entry * f, const struct hostent *hp, int cached)
{
    int k;

    if (fqdncache_get(name))
	fatal_dump("fqdncache_add: somebody adding a duplicate!");
    debug(35, 10, "fqdncache_add: Adding name '%s' (%s).\n", name,
	cached ? "cached" : "not cached");
    f->name = xstrdup(name);
    if (cached) {
	f->name_count = 0;
	f->names[f->name_count++] = xstrdup((char *) hp->h_name);
	for (k = 0; hp->h_aliases[k]; k++) {
	    f->names[f->name_count++] = xstrdup(hp->h_aliases[k]);
	    if (f->name_count == FQDN_MAX_NAMES)
		break;
	}
	f->lastref = squid_curtime;
	f->status = FQDN_CACHED;
	f->expires = squid_curtime + Config.positiveDnsTtl;
    } else {
	f->lastref = squid_curtime;
	f->status = FQDN_NEGATIVE_CACHED;
	f->expires = squid_curtime + Config.negativeDnsTtl;
    }
    fqdncache_add_to_hash(f);
}

/* walks down the pending list, calling handlers */
