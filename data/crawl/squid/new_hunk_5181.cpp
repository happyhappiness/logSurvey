
    assert(q->aq_state == AQ_STATE_SETUP);

    /* Find a free slot */
    slot = a_file_findslot(q);

    if (slot < 0) {
        debug(79, 1) ("WARNING: out of aiocb slots!\n");
        /* fall back to blocking method */
        file_read(fd, (char *) buf, req_len, offset, callback, data);
        return;
    }

    /* Mark slot as ours */
