 \par
 * "read" handler to accept FTP data connections.
 *
 \param fd	Handle/FD for the listening connection which has received a connect request.
 \param details	Some state data for the listening connection
 \param newfd	Handle/FD to the connection which has just been opened.
 \param flag	Error details for the listening connection. 
 \param xerrno	??
 \param data	??
 */
static void
ftpAcceptDataConnection(int fd, int newfd, ConnectionDetail *details,
                        comm_err_t flag, int xerrno, void *data)
{
    char ntoapeer[MAX_IPSTRLEN];
    FtpStateData *ftpState = (FtpStateData *)data;
    debugs(9, 3, HERE);

    if (flag == COMM_ERR_CLOSING)
        return;

    if (EBIT_TEST(ftpState->entry->flags, ENTRY_ABORTED)) {
        ftpState->abortTransaction("entry aborted when accepting data conn");
        return;
    }

