    void *s = const_cast<void *>(s_const);

    PROF_start(free_const);
    PROF_start(free);
    free(s);
    PROF_stop(free);
    PROF_stop(free_const);
}
