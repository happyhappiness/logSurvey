        comm_close(data.fd);
        data.fd = -1;
    }

#if ICAP_CLIENT

    if (icap) {
        icap->doneSending();
        return;
    }

#endif

    transactionForwardComplete();

    ftpSocketClosed(-1, this);
}

#if ICAP_CLIENT
