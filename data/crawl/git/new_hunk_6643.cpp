		else
			lo = mi + 1;
	} while (lo < hi);
	error("bad offset for revindex");
	return NULL;
}

void discard_revindex(void)
