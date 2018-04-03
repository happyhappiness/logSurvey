    }
}

CBDATA_TYPE(acl_size_t);

static void
dump_acl_b_size_t(StoreEntry * entry, const char *name, acl_size_t * head)
{
    acl_size_t *l;

    for (l = head; l; l = l->next) {
        if (l->size != static_cast<size_t>(-1))
            storeAppendPrintf(entry, "%s %d %s\n", name, (int) l->size, B_BYTES_STR);
        else
            storeAppendPrintf(entry, "%s none", name);

        dump_acl_list(entry, l->aclList);

        storeAppendPrintf(entry, "\n");
    }
}

static void
freed_acl_b_size_t(void *data)
{
    acl_size_t *l = static_cast<acl_size_t *>(data);
    aclDestroyAclList(&l->aclList);
}

static void
parse_acl_b_size_t(acl_size_t ** head)
{
    acl_size_t *l;
    acl_size_t **tail = head;	/* sane name below */

    CBDATA_INIT_TYPE_FREECB(acl_size_t, freed_acl_b_size_t);

    l = cbdataAlloc(acl_size_t);

    parse_b_size_t(&l->size);

    aclParseAclList(&l->aclList);

    while (*tail)
        tail = &(*tail)->next;

    *tail = l;
}

static void
free_acl_b_size_t(acl_size_t ** head)
{
    while (*head) {
        acl_size_t *l = *head;
        *head = l->next;
        l->next = NULL;
        cbdataFree(l);
    }
}

#if DELAY_POOLS

#include "DelayPools.h"
