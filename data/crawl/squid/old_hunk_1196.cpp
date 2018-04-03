#if USE_OPENSSL
    clientHttpsConnectionsOpen();
#endif

    if (NHttpSockets < 1)
        fatal("No HTTP or HTTPS ports configured");
}

void
clientHttpConnectionsClose(void)
{
    for (AnyP::PortCfgPointer s = HttpPortList; s != NULL; s = s->next) {
        if (s->listenConn != NULL) {
