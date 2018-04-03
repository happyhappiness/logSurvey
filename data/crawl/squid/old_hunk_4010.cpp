    }
}

void
QosConfig::dumpConfigLine(StoreEntry * entry, const char *name) const
{
    storeAppendPrintf(entry, "%s", name);

    if (tos_local_hit >0) {
        storeAppendPrintf(entry, " local-hit=%2x", tos_local_hit);
    }

    if (tos_sibling_hit >0) {
        storeAppendPrintf(entry, " sibling-hit=%2x", tos_sibling_hit);
    }
    if (tos_parent_hit >0) {
        storeAppendPrintf(entry, " parent-hit=%2x", tos_parent_hit);
    }
    if (preserve_miss_tos != 0) {
        storeAppendPrintf(entry, " disable-preserve-miss");
    }
    if (preserve_miss_tos && preserve_miss_tos_mask != 0) {
        storeAppendPrintf(entry, " miss-mask=%2x", preserve_miss_tos_mask);
    }
    storeAppendPrintf(entry, "\n");
}

#endif /* USE_ZPH_QOS */
