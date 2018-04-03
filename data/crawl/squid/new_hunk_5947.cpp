    if (unlink(buf) < 0)
#endif
    {
	DEBUG(1) {
	    fprintf(stderr, "%d UNLNK id %d %s: ", (int) mypid, r->id, buf);
	    perror("truncate");
	}
	return -errno;
    }
    DEBUG(2)
	fprintf(stderr, "%d UNLNK %s\n", (int) mypid, buf);
    return 0;
}

