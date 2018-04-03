	return ret;
}

int fetch(unsigned char *sha1)
{
	struct alt_base *altbase = alt;

	if (!fetch_object(altbase, sha1))
		return 0;
	while (altbase) {
		if (!fetch_pack(altbase, sha1))
			return 0;
		fetch_alternates(alt->base);
		altbase = altbase->next;
	}
	return error("Unable to find %s under %s", sha1_to_hex(sha1),
		     alt->base);
}

static inline int needs_quote(int ch)
