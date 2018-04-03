		}
		else
			return -1;
		hex_pfx[i] = c;
		if (!(i & 1))
			val <<= 4;
		bin_pfx[i >> 1] |= val;
	}
	return 0;
}

static int get_short_sha1(const char *name, int len, unsigned char *sha1,
			  unsigned flags)
{
	int status;
	char hex_pfx[40];
	unsigned char bin_pfx[20];
	struct disambiguate_state ds;
	int quietly = !!(flags & GET_SHA1_QUIETLY);

	if (len < MINIMUM_ABBREV || len > 40)
		return -1;
	if (prepare_prefixes(name, len, bin_pfx, hex_pfx) < 0)
		return -1;

	prepare_alt_odb();

	memset(&ds, 0, sizeof(ds));

	if (HAS_MULTI_BITS(flags & GET_SHA1_DISAMBIGUATORS))
		die("BUG: multiple get_short_sha1 disambiguator flags");

