{
    debugs(9, 4, HERE);
    ctrl.clear();
    mustStop("FtpStateData::ctrlClosed");
}

/// handler called by Comm when FTP data channel is closed unexpectedly
