    storeAppendPrintf(entry, "\n");
}

ClientDelayPools *
ClientDelayPools::Instance()
{
    static ClientDelayPools pools;
    return &pools;
}

ClientDelayPools::~ClientDelayPools()
{
    pools.clear();
}

void
ClientDelayConfig::finalize()
{
    for (unsigned int i = 0; i < pools().size(); ++i) {
        /* pools require explicit 'allow' to assign a client into them */
        if (!pool(i).access) {
            debugs(77, DBG_IMPORTANT, "WARNING: client_delay_pool #" << (i+1) <<
                   " has no client_delay_access configured. " <<
                   "No client will ever use it.");
        }
    }
}

void ClientDelayConfig::dumpPoolCount(StoreEntry * entry, const char *name) const
{
    const auto &pools_ = ClientDelayPools::Instance()->pools;
    if (pools_.size()) {
        storeAppendPrintf(entry, "%s %d\n", name, static_cast<int>(pools_.size()));
        for (unsigned int i = 0; i < pools_.size(); ++i)
            pools_[i]->dump(entry, i);
    }
}

void
ClientDelayConfig::freePools()
{
    pools().clear();
}

void ClientDelayConfig::parsePoolCount()
{
    if (pools().size()) {
        debugs(3, DBG_CRITICAL, "parse_client_delay_pool_count: multiple client_delay_pools lines, " <<
               "aborting all previous client_delay_pools config");
        freePools();
    }
    unsigned short pools_;
    ConfigParser::ParseUShort(&pools_);
    for (int i = 0; i < pools_; ++i)
        pools().push_back(new ClientDelayPool());
}

void ClientDelayConfig::parsePoolRates()
{
    if (unsigned short poolId = parsePoolId()) {
        --poolId;
        pool(poolId).rate = GetInteger();
        pool(poolId).highwatermark = GetInteger64();
    }
}

void ClientDelayConfig::parsePoolAccess(ConfigParser &parser)
{
    if (const unsigned short poolId = parsePoolId())
        aclParseAccessLine("client_delay_access", parser, &(pool(poolId-1).access));
}

unsigned short
ClientDelayConfig::parsePoolId()
{
    unsigned short poolId = 0;
    ConfigParser::ParseUShort(&poolId);
    if (poolId < 1 || poolId > pools().size()) {
        debugs(3, DBG_CRITICAL, "parse_client_delay_pool_rates: Ignoring pool " <<
               poolId << " not in 1 .. " << pools().size());
        return 0;
    }
    return poolId;
}

