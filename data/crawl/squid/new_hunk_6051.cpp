	memInUse(MEM_MEMOBJECT));
    storeAppendPrintf(sentry, "\t%6d Hot Object Cache Items\n",
	hot_obj_count);
    storeAppendPrintf(sentry, "\t%6d on-disk objects\n",
	n_disk_objects);

