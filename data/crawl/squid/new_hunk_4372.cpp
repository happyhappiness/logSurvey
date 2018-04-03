 \par
 * "read" handler to accept FTP data connections.
 *
 \param io comm accept(2) callback parameters
 */
void FtpStateData::ftpAcceptDataConnection(const CommAcceptCbParams &io)
{
    char ntoapeer[MAX_IPSTRLEN];
    debugs(9, 3, "ftpAcceptDataConnection");

    if (io.flag == COMM_ERR_CLOSING)
        return;

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        abortTransaction("entry aborted when accepting data conn");
        return;
    }

