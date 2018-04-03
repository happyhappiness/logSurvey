
ICAPConfig TheICAPConfig;

ICAPConfig::ICAPConfig(): preview_enable(0), preview_size(0),
    connect_timeout_raw(0), io_timeout_raw(0), reuse_connections(0),
    client_username_header(NULL), client_username_encode(0)
{
}

ICAPConfig::~ICAPConfig()
{
    // TODO: delete client_username_header?
}

Adaptation::ServicePointer
ICAPConfig::createService(const Adaptation::ServiceConfig &cfg)
{
    ICAPServiceRep::Pointer s = new ICAPServiceRep(cfg);
    s->finalize(s);
    return s.getRaw();
}

time_t ICAPConfig::connect_timeout(bool bypassable) const
{
    if (connect_timeout_raw > 0)
        return connect_timeout_raw; // explicitly configured

    return bypassable ? ::Config.Timeout.peer_connect : ::Config.Timeout.connect;
}

time_t ICAPConfig::io_timeout(bool) const
