    debug(20, i) ("  %6d were purged\n", n_purged);
    debug(20, i) ("  %6d were released\n", n_released);
    xfree(list);
}

static int
compareSize(StoreEntry ** e1, StoreEntry ** e2)
{
    if (!e1 || !e2)
	fatal_dump(NULL);
    if ((*e1)->mem_obj->e_current_len > (*e2)->mem_obj->e_current_len)
	return (1);
    if ((*e1)->mem_obj->e_current_len < (*e2)->mem_obj->e_current_len)
	return (-1);
    return (0);
}

static int
compareLastRef(StoreEntry ** e1, StoreEntry ** e2)
