Mgr::StoreToCommWriter::noteCommClosed(const CommCloseCbParams& params)
{
    debugs(16, 6, HERE);
    Must(fd == params.fd);
    fd = -1;
    mustStop("commClosed");
}

