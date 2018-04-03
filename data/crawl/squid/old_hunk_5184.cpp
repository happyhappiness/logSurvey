
    /* Initiate aio */
    if (aio_write(&qe->aq_e_aiocb) < 0) {
        fatalf("Aiee! aio_read() returned error (%d)!\n", errno);
        assert(1 == 0);
    }
}

