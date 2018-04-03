
        entry->complete();

        return;
    }

    debugs(16, 2, "CacheManager: " <<
           userName << "@" <<
           fd_table[fd].ipaddr << " requesting '" <<
           actionName << "'" );

    if (UsingSmp() && IamWorkerProcess()) {
        AsyncJob::Start(new Mgr::Forwarder(fd, cmd->params, request, entry));
        return;
    }

    Mgr::Action::Pointer action = cmd->profile->creator->create(cmd);
    Must(action != NULL);
    action->run(entry, true);
}

/*
 \ingroup CacheManagerInternal
 * Renders the protection level text for an action.
 * Also doubles as a check for the protection level.
 */
const char *
CacheManager::ActionProtection(const Mgr::ActionProfile::Pointer &profile)
{
    assert(profile != NULL);
    const char *pwd = PasswdGet(Config.passwd_list, profile->name);

    if (!pwd)
        return profile->isPwReq ? "hidden" : "public";

    if (!strcmp(pwd, "disable"))
        return "disabled";
