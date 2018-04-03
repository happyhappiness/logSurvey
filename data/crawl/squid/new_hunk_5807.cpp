	sd->max_size = size;
    }
    parse_cachedir_options(sd, NULL, 1);
    /* Enforce maxobjsize being set to something */
    if (sd->max_objsize == -1)
	fatal("COSS requires max-size to be set to something other than -1!\n");
}

void
