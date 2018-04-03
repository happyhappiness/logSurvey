    body_size *bs;
    bs = (body_size *) bodylist.head;
    while (bs) {
        acl_list *l;
	acl_access *head = bs->access_list;
	while (head != NULL) {
            storeAppendPrintf(entry, "%s %d %s", name, bs->maxsize, 
		head->allow ? "Allow" : "Deny");
	    for (l = head->acl_list; l != NULL; l = l->next) {
	        storeAppendPrintf(entry, " %s%s",
		    l->op ? null_string : "!",
		    l->acl->name);
	    }
	    storeAppendPrintf(entry, "\n");
	    head = head->next;
	}	    
	bs = (body_size *) bs->node.next;
    }
}

static void
free_body_size_t(dlink_list * bodylist) //acl_access ** head)
{
    body_size *bs, *tempnode;
    bs = (body_size *) bodylist->head;
    while (bs) {
        bs->maxsize = 0;
	aclDestroyAccessList(&bs->access_list);
	tempnode = (body_size *) bs->node.next;
	dlinkDelete (&bs->node, bodylist);
	cbdataFree (bs);
	bs = tempnode;
    }
}
