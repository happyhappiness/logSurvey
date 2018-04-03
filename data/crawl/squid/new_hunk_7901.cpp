	debug(20, 0, "%s", storeToString(e));
	fatal_dump(NULL);
    }
    destroy_MemObjectData(e->mem_obj);
    e->mem_obj->data = NULL;
    debug(20, 8, "storePurgeMem: Freeing %d in-memory bytes\n",
	e->object_len);
    debug(20, 8, "storePurgeMem: store_mem_size = %d\n", store_mem_size);
