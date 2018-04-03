    smsgid = msgget((key_t) ikey, 0700 | IPC_CREAT);

    if (smsgid < 0) {
        int xerrno = errno;
        debugs(50, DBG_CRITICAL, MYNAME << "msgget: " << xstrerr(xerrno));
        fatal("msgget failed");
    }

    rmsgid = msgget((key_t) (ikey + 1), 0700 | IPC_CREAT);

    if (rmsgid < 0) {
        int xerrno = errno;
        debugs(50, DBG_CRITICAL, MYNAME << "msgget: " << xstrerr(xerrno));
        fatal("msgget failed");
    }

