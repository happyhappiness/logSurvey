
/// handler called by Comm when FTP control channel is closed unexpectedly
void
Ftp::Client::ctrlClosed(const CommCloseCbParams &io)
{
    debugs(9, 4, HERE);
    ctrl.clear();
    mustStop("Ftp::Client::ctrlClosed");
}

void
Ftp::Client::timeout(const CommTimeoutCbParams &io)
{
    debugs(9, 4, HERE << io.conn << ": '" << entry->url() << "'" );

