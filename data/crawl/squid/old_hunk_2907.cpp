    return "protected";
}

/// \ingroup CacheManagerInternal
void
CacheManager::MenuAction::run(StoreEntry * sentry)
{
    CacheManagerActionList::iterator a;

    debugs(16, 4, "CacheManager::MenuCommand invoked");
    for (a = cmgr->ActionsList.begin(); a != cmgr->ActionsList.end(); ++a) {
        debugs(16, 5, "  showing action " << (*a)->action);
        storeAppendPrintf(sentry, " %-22s\t%-32s\t%s\n",
                          (*a)->action, (*a)->desc, cmgr->ActionProtection(*a));
    }
}
/// \ingroup CacheManagerInternal
CacheManager::MenuAction::MenuAction(CacheManager *aMgr) : CacheManagerAction ("menu", "Cache Manager Menu", 0, 1), cmgr(aMgr) { }

/*
 \ingroup CacheManagerInternal
 * gets from the global Config the password the user would need to supply
