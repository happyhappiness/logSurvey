
    /* Initiate aio */
    if (aio_read(&qe->aq_e_aiocb) < 0) {
        fatalf("Aiee! aio_read() returned error (%d)!\n", errno);
    }
}

