
    assert(mem_status == NOT_IN_MEMORY);

    if (!validLength()) {
        EBIT_SET(flags, ENTRY_BAD_LENGTH);
        releaseRequest();
    }

#if USE_CACHE_DIGESTS
    if (mem_obj->request)