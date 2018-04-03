    storeAppendPrintf(sentry, close_bracket);
}

void
parameter_get(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry,
	"{VM-Max %d \"# Maximum hot-vm cache (MB)\"}\n",
	Config.Mem.maxSize / (1 << 20));
    storeAppendPrintf(sentry,
	"{VM-High %d \"# High water mark hot-vm cache (%%)\"}\n",
	Config.Mem.highWaterMark);
    storeAppendPrintf(sentry,
	"{VM-Low %d \"# Low water mark hot-vm cache (%%)\"}\n",
	Config.Mem.lowWaterMark);
    storeAppendPrintf(sentry,
	"{Swap-Max %d \"# Maximum disk cache (MB)\"}\n",
	Config.Swap.maxSize / (1 << 10));
    storeAppendPrintf(sentry,
	"{Swap-High %d \"# High water mark disk cache (%%)\"}\n",
	Config.Swap.highWaterMark);
    storeAppendPrintf(sentry,
	"{Swap-Low %d \"# Low water mark disk cache (%%)\"}\n",
	Config.Swap.lowWaterMark);
    storeAppendPrintf(sentry,
	"{Neg-TTL %d \"# TTL for negative cache (s)\"}\n",
	Config.negativeTtl);
    storeAppendPrintf(sentry,
	"{ReadTimeout %d \"# Maximum idle connection (s)\"}\n",
	Config.Timeout.read);
    storeAppendPrintf(sentry, "{DeferTimeout %d\n", Config.Timeout.defer);
    storeAppendPrintf(sentry, "{ClientLifetime %d\n", Config.Timeout.lifetime);
    /* Cachemgr.cgi expects an integer in the second field of the string */
    storeAppendPrintf(sentry,
	"{HttpAccelMode %d \"# Is operating as an HTTP accelerator\"}\n",
	Config2.Accel.on);
    storeAppendPrintf(sentry, close_bracket);
}

static void
proto_newobject(cacheinfo * obj, protocol_t proto_id, int size, int restart)
{