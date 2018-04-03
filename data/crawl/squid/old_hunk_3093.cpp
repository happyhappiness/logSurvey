/// \ingroup CacheManagerInternal
CacheManager::ReconfigureAction::ReconfigureAction() : CacheManagerAction("reconfigure","Reconfigure Squid", 1, 1) { }

/// \ingroup CacheManagerInternal
void
CacheManager::OfflineToggleAction::run(StoreEntry * sentry)