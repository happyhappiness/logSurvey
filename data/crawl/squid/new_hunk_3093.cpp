/// \ingroup CacheManagerInternal
CacheManager::ReconfigureAction::ReconfigureAction() : CacheManagerAction("reconfigure","Reconfigure Squid", 1, 1) { }

/// \ingroup CacheManagerInternal
void
CacheManager::RotateAction::run(StoreEntry * sentry)
{
    debugs(16, DBG_IMPORTANT, "Rotate Logs by Cache Manager command.");
    storeAppendPrintf(sentry, "Rotating Squid Process Logs ....");
#ifdef _SQUID_LINUX_THREADS_
    rotate_logs(SIGQUIT);
#else
    rotate_logs(SIGUSR1);
#endif
}
/// \ingroup CacheManagerInternal
CacheManager::RotateAction::RotateAction() : CacheManagerAction("rotate","Rotate Squid Logs", 1, 1) { }

/// \ingroup CacheManagerInternal
void
CacheManager::OfflineToggleAction::run(StoreEntry * sentry)