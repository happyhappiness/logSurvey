    parseBytesLine(var, B_BYTES_STR);
}

CBDATA_TYPE(body_size);

static void
parse_body_size_t(dlink_list * bodylist)
{
    body_size *bs;
    CBDATA_INIT_TYPE(body_size);
    bs = cbdataAlloc(body_size);
    parse_size_t(&bs->maxsize);
    aclParseAccessLine(&bs->access_list);

    dlinkAddTail(bs, &bs->node, bodylist);
}

static void
dump_body_size_t(StoreEntry * entry, const char *name, dlink_list bodylist)
{
    body_size *bs;
    bs = (body_size *) bodylist.head;

    while (bs) {
        acl_list *l;
        acl_access *head = bs->access_list;

        while (head != NULL) {
            storeAppendPrintf(entry, "%s %ld %s", name, (long int) bs->maxsize,
                              head->allow ? "Allow" : "Deny");

            for (l = head->aclList; l != NULL; l = l->next) {
                storeAppendPrintf(entry, " %s%s",
                                  l->op ? null_string : "!",
                                  l->_acl->name);
            }

            storeAppendPrintf(entry, "\n");
            head = head->next;
        }

        bs = (body_size *) bs->node.next;
    }
}

static void
free_body_size_t(dlink_list * bodylist)
{
    body_size *bs, *tempnode;
    bs = (body_size *) bodylist->head;

    while (bs) {
        bs->maxsize = 0;
        aclDestroyAccessList(&bs->access_list);
        tempnode = (body_size *) bs->node.next;
        dlinkDelete(&bs->node, bodylist);
        cbdataFree(bs);
        bs = tempnode;
    }
}

static int
check_null_body_size_t(dlink_list bodylist)
{
    return bodylist.head == NULL;
}


static void
parse_kb_size_t(size_t * var)
{
