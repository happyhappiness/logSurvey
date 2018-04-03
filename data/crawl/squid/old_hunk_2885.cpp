Mgr::Forwarder::noteCommClosed(const CommCloseCbParams& params)
{
    debugs(16, 5, HERE);
    Must(fd == params.fd);
    fd = -1;
    mustStop("commClosed");
}

