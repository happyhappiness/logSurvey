    typedef Vector<ServiceConfig*>::const_iterator VISCI;
    const Vector<ServiceConfig*> &configs = serviceConfigs;
    debugs(93,3, "Found " << configs.size() << " service configs.");
    for (VISCI i = configs.begin(); i != configs.end(); ++i) {
        ServicePointer s = createService(**i);
        if (s != NULL)
            AllServices().push_back(s);
    }

    debugs(93,3, "Created " << configs.size() <<
        " message adaptation services.");
}

// poor man for_each
template <class Collection>
static void
FinalizeEach(Collection &collection, const char *label)
{
    typedef typename Collection::iterator CI;
    for (CI i = collection.begin(); i != collection.end(); ++i)
        (*i)->finalize();

    debugs(93,2, "Initialized " << collection.size() << ' ' << label);
}

void
Adaptation::Config::Finalize()
{
    FinalizeEach(AllServices(), "message adaptation services");
    FinalizeEach(AllGroups(), "message adaptation service groups");
    FinalizeEach(AllRules(), "message adaptation access rules");
}

void
Adaptation::Config::ParseServiceSet()
{
    ServiceSet *g = new ServiceSet();
    g->parse();
    AllGroups().push_back(g);
}

void
Adaptation::Config::FreeServiceSet()
{
    while (!AllGroups().empty()) {
		delete AllGroups().back();
		AllGroups().pop_back();
	}
}

void
Adaptation::Config::DumpServiceSet(StoreEntry *entry, const char *name)
{
    typedef Groups::iterator GI;
    for (GI i = AllGroups().begin(); i != AllGroups().end(); ++i)
        storeAppendPrintf(entry, "%s %s\n", name, (*i)->id.buf());
}

void
Adaptation::Config::ParseAccess(ConfigParser &parser)
{
    AccessRule *r = new AccessRule;
    r->parse(parser);
    AllRules().push_back(r);
}

void
Adaptation::Config::FreeAccess()
{
    while (!AllRules().empty()) {
        delete AllRules().back();
        AllRules().pop_back();
	}
}

void
Adaptation::Config::DumpAccess(StoreEntry *entry, const char *name)
{
    LOCAL_ARRAY(char, nom, 64);

    typedef AccessRules::iterator CI;
    for (CI i = AllRules().begin(); i != AllRules().end(); ++i) {
        snprintf(nom, 64, "%s %s", name, (*i)->groupId.buf());
        dump_acl_access(entry, nom, (*i)->acl);
	}
}

