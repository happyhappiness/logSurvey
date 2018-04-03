    return NULL;
}

void
ACL::Initialize()
{
    acl *a = Config.aclList;
    debug(53, 3) ("ACL::Initialize\n");

    while (a) {
        a->prepareForUse();
        a = a->next;
    }
}
