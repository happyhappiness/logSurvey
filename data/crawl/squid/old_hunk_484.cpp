    afterClientRead();
}

void
Server::clientWriteDone(const CommIoCbParams &io)
{
    debugs(33,5, io.conn);
    Must(writer != NULL);
    writer = NULL;

    /* Bail out quickly on Comm::ERR_CLOSING - close handlers will tidy up */
    if (io.flag == Comm::ERR_CLOSING) {
        debugs(33,5, io.conn << " closing Bailout.");
        return;
    }

    assert(Comm::IsConnOpen(clientConnection));
    assert(io.conn->fd == clientConnection->fd);

    writeSomeData(); // maybe schedules another write
}

