
    if (s->shm_offset > -1)
        buf = shmbuf + s->shm_offset;
    else {
        printf(stderr, "%d UNLNK id(%u) Error: no filename in shm buffer\n", (int) mypid, s->id);
        return EINVAL;
    }

    switch (r->mtype) {

