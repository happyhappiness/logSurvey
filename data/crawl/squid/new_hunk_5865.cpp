    cs->current_membuf = cs->membufs;
    cs->index.head = NULL;
    cs->index.tail = NULL;

    parse_cachedir_options(sd, NULL, 0);
}


static void
storeCossDirReconfigure(SwapDir * sd, int index, char *path)
{
    unsigned int i;
    unsigned int size;

    i = GetInteger();
    size = i << 10;		/* Mbytes to Kbytes */
    if (size <= 0)
	fatal("storeCossDirParse: invalid size value");

    if (size == sd->max_size)
	debug(3, 1) ("Cache COSS dir '%s' size remains unchanged at %d KB\n", path, size);
    else {
	debug(3, 1) ("Cache COSS dir '%s' size changed to %d KB\n", path, size);
	sd->max_size = size;
    }
    parse_cachedir_options(sd, NULL, 1);
}

void
