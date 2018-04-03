        ServicePointer s = at(p);
        if (s != NULL && s->cfg().key == checkedService->cfg().key)
            finalizeMsg("duplicate service name", s->cfg().key, false);
        else if (s != NULL && s->cfg().uri == checkedService->cfg().uri)
            finalizeMsg("duplicate service URI", s->cfg().uri, false);
    }
}

/// emits a formatted warning or error message at the appropriate dbg level
void
Adaptation::ServiceGroup::finalizeMsg(const char *msg, const String &culprit,
                                      bool error) const
{
    const int level = error ? DBG_CRITICAL :DBG_IMPORTANT;
    const char *pfx = error ? "ERROR: " : "WARNING: ";
    debugs(93,level, pfx << msg << ' ' << culprit << " in " << kind << " '" <<
           id << "'");
}

Adaptation::ServicePointer Adaptation::ServiceGroup::at(const Pos pos) const
{
    return FindService(services[pos]);
}

