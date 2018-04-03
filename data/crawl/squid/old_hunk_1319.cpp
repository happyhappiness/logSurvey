
/// handler called by Comm when FTP control channel is closed unexpectedly
void
ServerStateData::ctrlClosed(const CommCloseCbParams &io)
{
    debugs(9, 4, HERE);
    ctrl.clear();
    mustStop("Ftp::ServerStateData::ctrlClosed");
}

void
ServerStateData::timeout(const CommTimeoutCbParams &io)
{
    debugs(9, 4, HERE << io.conn << ": '" << entry->url() << "'" );

