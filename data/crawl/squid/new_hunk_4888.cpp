    FwdReplyCodes[tries][status]++;
}

void
FwdState::serversFree(FwdServer ** FSVR)
{
    FwdServer *fs;

    while ((fs = *FSVR)) {
        *FSVR = fs->next;
        fwdServerFree(fs);
    }
}

/**** PRIVATE NON-MEMBER FUNCTIONS ********************************************/

static void
fwdServerFree(FwdServer * fs)
{
    cbdataReferenceDone(fs->_peer);
    memFree(fs, MEM_FWD_SERVER);
}

static struct IN_ADDR
            aclMapAddr(acl_address * head, ACLChecklist * ch)
{
    acl_address *l;

    struct IN_ADDR addr;

    for (l = head; l; l = l->next)
    {
        if (ch->matchAclListFast(l->aclList))
            return l->addr;
    }

    addr.s_addr = INADDR_ANY;
    return addr;
}

static int
aclMapTOS(acl_tos * head, ACLChecklist * ch)
{
    acl_tos *l;

    for (l = head; l; l = l->next) {
        if (ch->matchAclListFast(l->aclList))
            return l->tos;
    }

    return 0;
}

struct IN_ADDR
            getOutgoingAddr(HttpRequest * request)
{
    ACLChecklist ch;

    if (request)
    {
        ch.src_addr = request->client_addr;
        ch.my_addr = request->my_addr;
        ch.my_port = request->my_port;
        ch.request = requestLink(request);
    }

    return aclMapAddr(Config.accessList.outgoing_address, &ch);
}

unsigned long
getOutgoingTOS(HttpRequest * request)
{
    ACLChecklist ch;

    if (request) {
        ch.src_addr = request->client_addr;
        ch.my_addr = request->my_addr;
        ch.my_port = request->my_port;
        ch.request = requestLink(request);
    }

    return aclMapTOS(Config.accessList.outgoing_tos, &ch);
}


/**** WIP_FWD_LOG *************************************************************/

#if WIP_FWD_LOG
void
fwdUninit(void)
