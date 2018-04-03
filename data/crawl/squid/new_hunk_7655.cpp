    return 0;
}

static int compareSize(e1, e2)
     StoreEntry **e1, **e2;
{
    if (!e1 || !e2)
	fatal_dump(NULL);
    if ((*e1)->mem_obj->e_current_len > (*e2)->mem_obj->e_current_len)
	return (1);
    if ((*e1)->mem_obj->e_current_len < (*e2)->mem_obj->e_current_len)
	return (-1);
    return (0);
}

static int compareLastRef(e1, e2)
     StoreEntry **e1, **e2;
{
    if (!e1 || !e2)
	fatal_dump(NULL);
    if ((*e1)->lastref > (*e2)->lastref)
	return (1);
    if ((*e1)->lastref < (*e2)->lastref)
	return (-1);
    return (0);
}

