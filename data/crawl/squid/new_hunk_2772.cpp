 */
void FtpStateData::ftpAcceptDataConnection(const CommAcceptCbParams &io)
{
    debugs(9, 3, HERE);

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortTransaction("entry aborted when accepting data conn");
        return;
    }

    if (io.flag != COMM_OK) {
        data.close();
        debugs(9, DBG_IMPORTANT, "FTP AcceptDataConnection: FD " << io.fd << ": " << xstrerr(io.xerrno));
        /** \todo Need to send error message on control channel*/
        ftpFail(this);
        return;
    }

    /* data listening conn is no longer even open. abort. */
    if (data.fd <= 0 || fd_table[data.fd].flags.open == 0) {
        data.clear(); // ensure that it's cleared and not just closed.
        return;
    }

    /** \par
     * When squid.conf ftp_sanitycheck is enabled, check the new connection is actually being
     * made by the remote client which is connected to the FTP control socket.
     * Or the one which we were told to listen for by control channel messages (may differ under NAT).
     * This prevents third-party hacks, but also third-party load balancing handshakes.
     */
    if (Config.Ftp.sanitycheck) {
        char ntoapeer[MAX_IPSTRLEN];
        io.details.peer.NtoA(ntoapeer,MAX_IPSTRLEN);

        if (strcmp(fd_table[ctrl.fd].ipaddr, ntoapeer) != 0 &&
                strcmp(fd_table[data.fd].ipaddr, ntoapeer) != 0) {
            debugs(9, DBG_IMPORTANT,
                   "FTP data connection from unexpected server (" <<
                   io.details.peer << "), expecting " <<
                   fd_table[ctrl.fd].ipaddr << " or " << fd_table[data.fd].ipaddr);

            /* close the bad sources connection down ASAP. */
            comm_close(io.nfd);

            /* drop the bad connection (io) by ignoring the attempt. */
            return;
        }
    }

    /**\par
     * Replace the Listening socket with the accepted data socket */
    data.close();
    data.opened(io.nfd, dataCloser());
    data.port = io.details.peer.GetPort();
    data.host = xstrdup(fd_table[io.nfd].ipaddr);

    debugs(9, 3, "ftpAcceptDataConnection: Connected data socket on " <<
           "FD " << io.nfd << " to " << io.details.peer << " FD table says: " <<
           "ctrl-peer= " << fd_table[ctrl.fd].ipaddr << ", " <<
           "data-peer= " << fd_table[data.fd].ipaddr);

    assert(haveControlChannel("ftpAcceptDataConnection"));
    assert(ctrl.message == NULL);

    // Ctrl channel operations will determine what happens to this data connection
}

/// \ingroup ServerProtocolFTPInternal
