    typedef Vector<ServiceConfig*>::const_iterator VISCI;
    const Vector<ServiceConfig*> &configs = serviceConfigs;
    debugs(93,3, "Found " << configs.size() << " service configs.");
    for (VISCI ci = configs.begin(); ci != configs.end(); ++ci) {
        ServicePointer s = createService(**ci);
        if (s != NULL)
            AddService(s);
    }

    debugs(93,1, "Initialized " << configs.size() <<
        " message adaptation services.");
}

void
Adaptation::Config::Finalize()
{
    // link classes with the service reps they use
    typedef Classes::iterator CI;
    for (CI ci = AllClasses().begin(); ci != AllClasses().end(); ++ci) {
        Class *c = *ci;
        c->finalize(); // TODO: fail on failures
    }

    debugs(93,2, "Initialized " << AllClasses().size() <<
        " message adaptation service classes.");
}

void
Adaptation::Config::parseClass()
{
    Class *C = new Class();

    if (C->prepare()) {
        AddClass(C);
    } else {
        delete C;
    }
};

void
Adaptation::Config::freeClass()
{
    // XXX: leaking Classes here?
}

void
Adaptation::Config::dumpClass(StoreEntry *entry, const char *name) const
{
    typedef Classes::iterator CI;
    for (CI i = AllClasses().begin(); i != AllClasses().end(); ++i)
        storeAppendPrintf(entry, "%s %s\n", name, (*i)->key.buf());
}

void
Adaptation::Config::parseAccess(ConfigParser &parser)
{
    String aKey;
    ConfigParser::ParseString(&aKey);
    Class *c = FindClass(aKey);

    if (!c)
        fatalf("Did not find  class '%s' referenced on line %d\n",
               aKey.buf(), config_lineno);

    aclParseAccessLine(parser, &c->accessList);
};

void
Adaptation::Config::freeAccess()
{
    (void) 0;
}

void
Adaptation::Config::dumpAccess(StoreEntry *entry, const char *name) const
{
    LOCAL_ARRAY(char, nom, 64);

    typedef Classes::iterator CI;
    for (CI i = AllClasses().begin(); i != AllClasses().end(); ++i) {
        snprintf(nom, 64, "%s %s", name, (*i)->key.buf());
        dump_acl_access(entry, nom, (*i)->accessList);
	}
}

