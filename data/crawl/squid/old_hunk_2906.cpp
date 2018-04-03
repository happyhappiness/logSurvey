
        entry->complete();

        StateFree(mgr);

        return;
    }

    debugs(16, 2, "CacheManager: " <<
           (mgr->user_name ? mgr->user_name : "<unknown>") << "@" <<
           fd_table[fd].ipaddr << " requesting '" <<
           mgr->action << "'" );
    /* retrieve object requested */
    a = findAction(mgr->action);
    assert(a != NULL);

    entry->buffer();

    {
        HttpReply *rep = new HttpReply;
        rep->setHeaders(HTTP_OK, NULL, "text/plain", -1, squid_curtime, squid_curtime);
        entry->replaceHttpReply(rep);
    }

    a->run(entry);

    entry->flush();

    if (a->flags.atomic)
        entry->complete();

    StateFree(mgr);
}

/// \ingroup CacheManagerInternal
void CacheManager::ShutdownAction::run(StoreEntry *sentry)
{
    debugs(16, DBG_CRITICAL, "Shutdown by Cache Manager command.");
    shut_down(0);
}
/// \ingroup CacheManagerInternal
CacheManager::ShutdownAction::ShutdownAction() : CacheManagerAction("shutdown","Shut Down the Squid Process", 1, 1) { }

/// \ingroup CacheManagerInternal
void
CacheManager::ReconfigureAction::run(StoreEntry * sentry)
{
    debugs(16, DBG_IMPORTANT, "Reconfigure by Cache Manager command.");
    storeAppendPrintf(sentry, "Reconfiguring Squid Process ....");
    reconfigure(SIGHUP);
}
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
{
    Config.onoff.offline = !Config.onoff.offline;
    debugs(16, DBG_IMPORTANT, "offline_mode now " << (Config.onoff.offline ? "ON" : "OFF") << " by Cache Manager request.");

    storeAppendPrintf(sentry, "offline_mode is now %s\n",
                      Config.onoff.offline ? "ON" : "OFF");
}
/// \ingroup CacheManagerInternal
CacheManager::OfflineToggleAction::OfflineToggleAction() : CacheManagerAction ("offline_toggle", "Toggle offline_mode setting", 1, 1) { }

/*
 \ingroup CacheManagerInternal
 * Renders the protection level text for an action.
 * Also doubles as a check for the protection level.
 */
const char *
CacheManager::ActionProtection(const CacheManagerAction * at)
{
    char *pwd;
    assert(at);
    pwd = PasswdGet(Config.passwd_list, at->action);

    if (!pwd)
        return at->flags.pw_req ? "hidden" : "public";

    if (!strcmp(pwd, "disable"))
        return "disabled";
