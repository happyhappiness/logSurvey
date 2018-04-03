    commSetTimeout(ftpState->data.fd, 15, FtpStateData::ftpTimeout, ftpState);
}

static void
ftpReadPasv(FtpStateData * ftpState)
{
