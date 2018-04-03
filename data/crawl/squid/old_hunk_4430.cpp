                      IpcacheStats.invalid);
    storeAppendPrintf(sentry, "\n\n");
    storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " %-29.29s %3s %6s %6s %1s\n",
                      "Hostname",
                      "Flg",
                      "lstref",
                      "TTL",
                      "N");

    for (m = lru_list.head; m; m = m->next)
        ipcacheStatPrint((ipcache_entry *)m->data, sentry);
}

static void
dummy_handler(const ipcache_addrs * addrsnotused, void *datanotused)
{
    return;
}

void
