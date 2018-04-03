Mgr::Forwarder::noteCommClosed(const CommCloseCbParams& params)
{
    debugs(16, 5, HERE);
    Must(!Comm::IsConnOpen(clientConnection));
    mustStop("commClosed");
}

