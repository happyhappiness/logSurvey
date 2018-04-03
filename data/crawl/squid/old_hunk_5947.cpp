    if (unlink(buf) < 0)
#endif
    {
	fprintf(stderr, "%d UNLNK id %d %s: ", (int) mypid, r->id, buf);
	perror("truncate");
	return -errno;
    }
#if STDERR_DEBUG
    fprintf(stderr, "%d UNLNK %s\n", (int) mypid, buf);
#endif
    return 0;
}

