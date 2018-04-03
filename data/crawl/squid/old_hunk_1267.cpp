        return;
    }

    static MemBuf mb;
    mb.reset();
    if (params.size() > 0)
        mb.Printf("%s %s%s", cmd.termedBuf(), params.termedBuf(), Ftp::crlf);
    else
        mb.Printf("%s%s", cmd.termedBuf(), Ftp::crlf);

    writeCommand(mb.content());

    state =
        serverState() == fssHandleCdup ? SENT_CDUP :
