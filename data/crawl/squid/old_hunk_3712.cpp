    wordlistDestroy(&names);
}

void
Adaptation::ServiceGroup::finalize()
{
    for (iterator i = services.begin(); i != services.end(); ++i) {
        const String &id = *i;
        // TODO: fail on failures
        if (!FindService(id))
            debugs(93,0, "ERROR: Unknown adaptation name: " << id);
    }
    debugs(93,7, HERE << "finalized " << kind << ": " << id);
}

/* ServiceSet */

Adaptation::ServiceSet::ServiceSet(): ServiceGroup("adaptation set")
{
}

Adaptation::ServiceGroup::Loop Adaptation::ServiceSet::initialServices()
{
    return Loop(services.begin(), services.end());
}

#if FUTURE_OPTIMIZATION
void
Adaptation::ServiceSet::finalize()
{
    ServiceGroup::finalize();

    for (wordlist *iter = service_names; iter; iter = iter->next) {
        ServicePointer match = Config::FindService(iter->id);
        if (match != NULL)
            services += match;
    }
}
#endif


/* SingleService */

Adaptation::SingleService::SingleService(const String &aServiceId):
        ServiceGroup("single-service group")
{
    id = aServiceId;
    services.push_back(aServiceId);
}

Adaptation::ServiceGroup::Loop
Adaptation::SingleService::initialServices()
{
    return Loop(services.begin(), services.end()); // there should be only one
}


