    Ftp::StartListening();

    if (NHttpSockets < 1)
        fatal("No HTTP, HTTPS or FTP ports configured");
}

void
clientConnectionsClose(void)
{
    for (AnyP::PortCfgPointer s = HttpPortList; s != NULL; s = s->next) {
        if (s->listenConn != NULL) {
