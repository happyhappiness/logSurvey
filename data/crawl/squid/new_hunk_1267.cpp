        return;
    }

    SBuf buf;
    if (params.size() > 0)
        buf.Printf("%s %s%s", cmd.termedBuf(), params.termedBuf(), Ftp::crlf);
    else
        buf.Printf("%s%s", cmd.termedBuf(), Ftp::crlf);

    writeCommand(buf.c_str());

    state =
        serverState() == fssHandleCdup ? SENT_CDUP :
