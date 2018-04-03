    fatal(message);
}

dlink_node *
dlinkNodeNew()
{
    return new dlink_node;
}

/* the node needs to be unlinked FIRST */
