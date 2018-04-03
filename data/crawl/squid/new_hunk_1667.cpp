    return true;
}

bool
ServerStateData::handleEpsvReply(Ip::Address &remoteAddr)
{
    int code = ctrl.replycode;
    char *buf;
    debugs(9, 3, HERE);

    if (code != 229 && code != 522) {
        if (code == 200) {
            /* handle broken servers (RFC 2428 says OK code for EPSV MUST be 229 not 200) */
            /* vsftpd for one send '200 EPSV ALL ok.' without even port info.
             * Its okay to re-send EPSV 1/2 but nothing else. */
            debugs(9, DBG_IMPORTANT, "Broken FTP Server at " << ctrl.conn->remote << ". Wrong accept code for EPSV");
        } else {
            debugs(9, 2, "EPSV not supported by remote end");
        }
        return sendPassive();
    }

    if (code == 522) {
        /* server response with list of supported methods   */
        /*   522 Network protocol not supported, use (1)    */
        /*   522 Network protocol not supported, use (1,2)  */
        /*   522 Network protocol not supported, use (2)  */
        /* TODO: handle the (1,2) case. We might get it back after EPSV ALL
         * which means close data + control without self-destructing and re-open from scratch. */
        debugs(9, 5, HERE << "scanning: " << ctrl.last_reply);
        buf = ctrl.last_reply;
        while (buf != NULL && *buf != '\0' && *buf != '\n' && *buf != '(')
            ++buf;
        if (buf != NULL && *buf == '\n')
            ++buf;

        if (buf == NULL || *buf == '\0') {
            /* handle broken server (RFC 2428 says MUST specify supported protocols in 522) */
            debugs(9, DBG_IMPORTANT, "Broken FTP Server at " << ctrl.conn->remote << ". 522 error missing protocol negotiation hints");
            return sendPassive();
        } else if (strcmp(buf, "(1)") == 0) {
            state = SENT_EPSV_2; /* simulate having sent and failed EPSV 2 */
            return sendPassive();
        } else if (strcmp(buf, "(2)") == 0) {
            if (Ip::EnableIpv6) {
                /* If server only supports EPSV 2 and we have already tried that. Go straight to EPRT */
                if (state == SENT_EPSV_2) {
                    return sendEprt();
                } else {
                    /* or try the next Passive mode down the chain. */
                    return sendPassive();
                }
            } else {
                /* Server only accept EPSV in IPv6 traffic. */
                state = SENT_EPSV_1; /* simulate having sent and failed EPSV 1 */
                return sendPassive();
            }
        } else {
            /* handle broken server (RFC 2428 says MUST specify supported protocols in 522) */
            debugs(9, DBG_IMPORTANT, "WARNING: Server at " << ctrl.conn->remote << " sent unknown protocol negotiation hint: " << buf);
            return sendPassive();
        }
        failed(ERR_FTP_FAILURE, 0);
        return false;
    }

    /*  229 Entering Extended Passive Mode (|||port|) */
    /*  ANSI sez [^0-9] is undefined, it breaks on Watcom cc */
    debugs(9, 5, "scanning: " << ctrl.last_reply);

    buf = ctrl.last_reply + strcspn(ctrl.last_reply, "(");

    char h1, h2, h3, h4;
    unsigned short port;
    int n = sscanf(buf, "(%c%c%c%hu%c)", &h1, &h2, &h3, &port, &h4);

    if (n < 4 || h1 != h2 || h1 != h3 || h1 != h4) {
        debugs(9, DBG_IMPORTANT, "Invalid EPSV reply from " <<
               ctrl.conn->remote << ": " <<
               ctrl.last_reply);

        return sendPassive();
    }

    if (0 == port) {
        debugs(9, DBG_IMPORTANT, "Unsafe EPSV reply from " <<
               ctrl.conn->remote << ": " <<
               ctrl.last_reply);

        return sendPassive();
    }

    if (Config.Ftp.sanitycheck) {
        if (port < 1024) {
            debugs(9, DBG_IMPORTANT, "Unsafe EPSV reply from " <<
                   ctrl.conn->remote << ": " <<
                   ctrl.last_reply);

            return sendPassive();
        }
    }

    remoteAddr = ctrl.conn->remote;
    remoteAddr.port(port);
    data.addr(remoteAddr);
    return true;
}

// The server-side EPRT and PORT commands are not yet implemented.
// The ServerStateData::sendEprt() will fail because of the unimplemented
// openListenSocket() or sendPort() methods
bool
ServerStateData::sendEprt()
{
    if (!Config.Ftp.eprt) {
        /* Disabled. Switch immediately to attempting old PORT command. */
        debugs(9, 3, "EPRT disabled by local administrator");
        return sendPort();
    }

    debugs(9, 3, HERE);

    if (!openListenSocket()) {
        failed(ERR_FTP_FAILURE, 0);
        return false;
    }

    debugs(9, 3, "Listening for FTP data connection with FD " << data.conn);
    if (!Comm::IsConnOpen(data.conn)) {
        /* XXX Need to set error message */
        failed(ERR_FTP_FAILURE, 0);
        return false;
    }

    static MemBuf mb;
    mb.reset();
    char buf[MAX_IPSTRLEN];
    /* RFC 2428 defines EPRT as IPv6 equivalent to IPv4 PORT command. */
    /* Which can be used by EITHER protocol. */
    debugs(9, 3, "Listening for FTP data connection on port" << comm_local_port(data.conn->fd) << " or port?" << data.conn->local.port());
    mb.Printf("EPRT |%d|%s|%d|%s",
              ( data.conn->local.isIPv6() ? 2 : 1 ),
              data.conn->local.toStr(buf,MAX_IPSTRLEN),
              comm_local_port(data.conn->fd), Ftp::crlf );

    state = SENT_EPRT;
    writeCommand(mb.content());
    return true;
}

bool
ServerStateData::sendPort()
{
    failed(ERR_FTP_FAILURE, 0);
    return false;
}

bool
ServerStateData::sendPassive()
{
    debugs(9, 3, HERE);

    /** \par
      * Checks for EPSV ALL special conditions:
      * If enabled to be sent, squid MUST NOT request any other connect methods.
      * If 'ALL' is sent and fails the entire FTP Session fails.
      * NP: By my reading exact EPSV protocols maybe attempted, but only EPSV method. */
    if (Config.Ftp.epsv_all && state == SENT_EPSV_1 ) {
        // We are here because the last "EPSV 1" failed, but because of epsv_all
        // no other method allowed.
        debugs(9, DBG_IMPORTANT, "FTP does not allow PASV method after 'EPSV ALL' has been sent.");
        failed(ERR_FTP_FAILURE, 0);
        return false;
    }


    /// Closes any old FTP-Data connection which may exist. */
    data.close();

    /** \par
      * Checks for previous EPSV/PASV failures on this server/session.
      * Diverts to EPRT immediately if they are not working. */
    if (!Config.Ftp.passive || state == SENT_PASV) {
        sendEprt();
        return true;
    }

    static MemBuf mb;
    mb.reset();
    /** \par
      * Send EPSV (ALL,2,1) or PASV on the control channel.
      *
      *  - EPSV ALL  is used if enabled.
      *  - EPSV 2    is used if ALL is disabled and IPv6 is available and ctrl channel is IPv6.
      *  - EPSV 1    is used if EPSV 2 (IPv6) fails or is not available or ctrl channel is IPv4.
      *  - PASV      is used if EPSV 1 fails.
      */
    switch (state) {
    case SENT_EPSV_ALL: /* EPSV ALL resulted in a bad response. Try ther EPSV methods. */
        if (ctrl.conn->local.isIPv6()) {
            debugs(9, 5, HERE << "FTP Channel is IPv6 (" << ctrl.conn->remote << ") attempting EPSV 2 after EPSV ALL has failed.");
            mb.Printf("EPSV 2%s", Ftp::crlf);
            state = SENT_EPSV_2;
            break;
        }
        // else fall through to skip EPSV 2

    case Ftp::ServerStateData::SENT_EPSV_2: /* EPSV IPv6 failed. Try EPSV IPv4 */
        if (ctrl.conn->local.isIPv4()) {
            debugs(9, 5, HERE << "FTP Channel is IPv4 (" << ctrl.conn->remote << ") attempting EPSV 1 after EPSV ALL has failed.");
            mb.Printf("EPSV 1%s", Ftp::crlf);
            state = SENT_EPSV_1;
            break;
        } else if (Config.Ftp.epsv_all) {
            debugs(9, DBG_IMPORTANT, "FTP does not allow PASV method after 'EPSV ALL' has been sent.");
            failed(ERR_FTP_FAILURE, 0);
            return false;
        }
        // else fall through to skip EPSV 1

    case SENT_EPSV_1: /* EPSV options exhausted. Try PASV now. */
        debugs(9, 5, HERE << "FTP Channel (" << ctrl.conn->remote << ") rejects EPSV connection attempts. Trying PASV instead.");
        mb.Printf("PASV%s", Ftp::crlf);
        state = SENT_PASV;
        break;

    default:
        if (!Config.Ftp.epsv) {
            debugs(9, 5, HERE << "EPSV support manually disabled. Sending PASV for FTP Channel (" << ctrl.conn->remote <<")");
            mb.Printf("PASV%s", Ftp::crlf);
            state = SENT_PASV;
        } else if (Config.Ftp.epsv_all) {
            debugs(9, 5, HERE << "EPSV ALL manually enabled. Attempting with FTP Channel (" << ctrl.conn->remote <<")");
            mb.Printf("EPSV ALL%s", Ftp::crlf);
            state = SENT_EPSV_ALL;
        } else {
            if (ctrl.conn->local.isIPv6()) {
                debugs(9, 5, HERE << "FTP Channel (" << ctrl.conn->remote << "). Sending default EPSV 2");
                mb.Printf("EPSV 2%s", Ftp::crlf);
                state = SENT_EPSV_2;
            }
            if (ctrl.conn->local.isIPv4()) {
                debugs(9, 5, HERE << "Channel (" << ctrl.conn->remote <<"). Sending default EPSV 1");
                mb.Printf("EPSV 1%s", Ftp::crlf);
                state = SENT_EPSV_1;
            }
        }
        break;
    }

    if (ctrl.message)
        wordlistDestroy(&ctrl.message);
    ctrl.message = NULL; //No message to return to client.
    ctrl.offset = 0; //reset readed response, to make room read the next response

    writeCommand(mb.content());
    
    return true;


    /*
     * ugly hack for ftp servers like ftp.netscape.com that sometimes
     * dont acknowledge PASV commands. Use connect timeout to be faster then read timeout (minutes).
     */
    /*
    typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
    AsyncCall::Pointer timeoutCall =  JobCallback(9, 5,
                                      TimeoutDialer, ftpState, FtpStateData::timeout);
    commSetConnTimeout(ftpState->ctrl.conn, Config.Timeout.connect, timeoutCall);
    return true;
    */
}


void
ServerStateData::connectDataChannel()
{
