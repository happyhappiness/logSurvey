    storeAppendPrintf(entry, "\n");
}

void
ClientDelayConfig::finalize()
{
    for (unsigned int i = 0; i < pools.size(); ++i) {
        /* pools require explicit 'allow' to assign a client into them */
        if (!pools[i].access) {
            debugs(77, DBG_IMPORTANT, "client_delay_pool #" << (i+1) <<
                   " has no client_delay_access configured. " <<
                   "No client will ever use it.");
        }
    }
}

void ClientDelayConfig::freePoolCount()
{
    pools.clear();
}

void ClientDelayConfig::dumpPoolCount(StoreEntry * entry, const char *name) const
{
    if (pools.size()) {
        storeAppendPrintf(entry, "%s %d\n", name, (int)pools.size());
        for (unsigned int i = 0; i < pools.size(); ++i)
            pools[i].dump(entry, i);
    }
}

void ClientDelayConfig::parsePoolCount()
{
    if (pools.size()) {
        debugs(3, DBG_CRITICAL, "parse_client_delay_pool_count: multiple client_delay_pools lines, aborting all previous client_delay_pools config");
        clean();
    }
    unsigned short pools_;
    ConfigParser::ParseUShort(&pools_);
    for (int i = 0; i < pools_; ++i) {
        pools.push_back(ClientDelayPool());
    }
}

void ClientDelayConfig::parsePoolRates()
{
    unsigned short pool;
    ConfigParser::ParseUShort(&pool);

    if (pool < 1 || pool > pools.size()) {
        debugs(3, DBG_CRITICAL, "parse_client_delay_pool_rates: Ignoring pool " << pool << " not in 1 .. " << pools.size());
        return;
    }

    --pool;

    pools[pool].rate = GetInteger();
    pools[pool].highwatermark = GetInteger64();
}

void ClientDelayConfig::parsePoolAccess(ConfigParser &parser)
{
    unsigned short pool;

    ConfigParser::ParseUShort(&pool);

    if (pool < 1 || pool > pools.size()) {
        debugs(3, DBG_CRITICAL, "parse_client_delay_pool_rates: Ignoring pool " << pool << " not in 1 .. " << pools.size());
        return;
    }

    --pool;
    aclParseAccessLine("client_delay_access", parser, &pools[pool].access);
}

void ClientDelayConfig::clean()
{
    for (unsigned int i = 0; i < pools.size(); ++i) {
        aclDestroyAccessList(&pools[i].access);
    }
}

