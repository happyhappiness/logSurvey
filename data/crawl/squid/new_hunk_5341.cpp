    assert(asinfo->as_number);

    for (q = asinfo->as_number; q; q = q->next)
        storeAppendPrintf(sentry, " %d", q->element);

    storeAppendPrintf(sentry, "\n");

    return 0;
}

MemPool *ACLASN::Pool(NULL);
void *
ACLASN::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (ACLASN));

    if (!Pool)
        Pool = memPoolCreate("ACLASN", sizeof (ACLASN));

    return memPoolAlloc(Pool);
}

void
ACLASN::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
ACLASN::deleteSelf() const
{
    delete this;
}

ACLASN::~ACLASN()
{
    if (data)
        data->deleteSelf();
}

bool

ACLASN::match(struct in_addr toMatch)
{
    return asnMatchIp(data, toMatch);
}

wordlist *
ACLASN::dump()
{
    wordlist *W = NULL;
    char buf[32];
    List<int> *ldata = data;

    while (ldata != NULL) {
        snprintf(buf, sizeof(buf), "%d", ldata->element);
        wordlistAdd(&W, buf);
        ldata = ldata->next;
    }

    return W;
}

void
ACLASN::parse()
{
    List<int> **curlist = &data;
    List<int> **Tail;
    List<int> *q = NULL;
    char *t = NULL;

    for (Tail = curlist; *Tail; Tail = &((*Tail)->next))

        ;
    while ((t = strtokFile())) {
        q = new List<int> (atoi(t));
        *(Tail) = q;
        Tail = &q->next;
    }
}

ACLData<struct in_addr> *
ACLASN::clone() const
{
    if (data)
        fatal ("cloning of ACLASN not implemented");

    return new ACLASN(*this);
}

ACL::Prototype ACLASN::SourceRegistryProtoype(&ACLASN::SourceRegistryEntry_, "src_as");
ACLStrategised<struct in_addr> ACLASN::SourceRegistryEntry_(new ACLASN, ACLSourceASNStrategy::Instance(), "src_as");
ACL::Prototype ACLASN::DestinationRegistryProtoype(&ACLASN::DestinationRegistryEntry_, "dst_as");
ACLStrategised<struct in_addr> ACLASN::DestinationRegistryEntry_(new ACLASN, ACLDestinationASNStrategy::Instance(), "dst_as");

int
ACLSourceASNStrategy::match (ACLData<MatchType> * &data, ACLChecklist *checklist)
{
    return data->match(checklist->src_addr);
}

ACLSourceASNStrategy *
ACLSourceASNStrategy::Instance()
{
    return &Instance_;
}

ACLSourceASNStrategy ACLSourceASNStrategy::Instance_;


int
ACLDestinationASNStrategy::match (ACLData<MatchType> * &data, ACLChecklist *checklist)
{
    const ipcache_addrs *ia = ipcache_gethostbyname(checklist->request->host, IP_LOOKUP_IF_MISS);

    if (ia) {
        for (int k = 0; k < (int) ia->count; k++) {
            if (data->match(ia->in_addrs[k]))
                return 1;
        }

        return 0;
    } else if (!checklist->request->flags.destinationIPLookedUp()) {
        /* No entry in cache, lookup not attempted */
        /* XXX FIXME: allow accessing the acl name here */
        debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
                      "unknown" /*name*/, checklist->request->host);
        checklist->changeState (DestinationIPLookup::Instance());
    } else {
        return data->match(no_addr);
    }

    return 0;
}

ACLDestinationASNStrategy *
ACLDestinationASNStrategy::Instance()
{
    return &Instance_;
}

ACLDestinationASNStrategy ACLDestinationASNStrategy::Instance_;
