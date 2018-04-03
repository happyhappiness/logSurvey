 */
void FtpStateData::ftpAcceptDataConnection(const CommAcceptCbParams &io)
{
    char ntoapeer[MAX_IPSTRLEN];
    debugs(9, 3, "ftpAcceptDataConnection");

    // one connection accepted. the handler has stopped listening. drop our local pointer to it.
    data.listener = NULL;

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortTransaction("entry aborted when accepting data conn");
        return;
    }

    /** \par
     * When squid.conf ftp_sanitycheck is enabled, check the new connection is actually being
     * made by the remote client which is connected to the FTP control socket.
     * This prevents third-party hacks, but also third-party load balancing handshakes.
     */
    if (Config.Ftp.sanitycheck) {
        io.details.peer.NtoA(ntoapeer,MAX_IPSTRLEN);

        if (strcmp(fd_table[ctrl.fd].ipaddr, ntoapeer) != 0) {
            debugs(9, DBG_IMPORTANT,
                   "FTP data connection from unexpected server (" <<
                   io.details.peer << "), expecting " <<
                   fd_table[ctrl.fd].ipaddr);

            /* close the bad soures connection down ASAP. */
            comm_close(io.nfd);

            /* we are ony accepting once, so need to re-open the listener socket. */
            typedef CommCbMemFunT<FtpStateData, CommAcceptCbParams> acceptDialer;
            AsyncCall::Pointer acceptCall = JobCallback(11, 5,
                                            acceptDialer, this, FtpStateData::ftpAcceptDataConnection);
            data.listener = new Comm::ListenStateData(data.fd, acceptCall, false);
            return;
        }
    }

    if (io.flag != COMM_OK) {
        debugs(9, DBG_IMPORTANT, "ftpHandleDataAccept: FD " << io.nfd << ": " << xstrerr(io.xerrno));
        /** \todo XXX Need to set error message */
        ftpFail(this);
        return;
    }

    /**\par
     * Replace the Listen socket with the accepted data socket */
    data.close();
    data.opened(io.nfd, dataCloser());
    data.port = io.details.peer.GetPort();
    io.details.peer.NtoA(data.host,SQUIDHOSTNAMELEN);

    debugs(9, 3, "ftpAcceptDataConnection: Connected data socket on " <<
           "FD " << io.nfd << " to " << io.details.peer << " FD table says: " <<
           "ctrl-peer= " << fd_table[ctrl.fd].ipaddr << ", " <<
           "data-peer= " << fd_table[data.fd].ipaddr);


    AsyncCall::Pointer nullCall = NULL;
    commSetTimeout(ctrl.fd, -1, nullCall);

    typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
    AsyncCall::Pointer timeoutCall =  JobCallback(9, 5,
                                      TimeoutDialer, this, FtpStateData::ftpTimeout);
    commSetTimeout(data.fd, Config.Timeout.read, timeoutCall);

    /*\todo XXX We should have a flag to track connect state...
     *    host NULL -> not connected, port == local port
     *    host set  -> connected, port == remote port
     */
    /* Restart state (SENT_NLST/LIST/RETR) */
    FTP_SM_FUNCS[state] (this);
}

/// \ingroup ServerProtocolFTPInternal
