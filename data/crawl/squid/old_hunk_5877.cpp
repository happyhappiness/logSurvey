{
    dlink_node *link = memAllocate(MEM_DLINK_NODE);
    dlinkAddTail(r, link, &srv->queue);
    /* XXX No queue length check here? */
}


