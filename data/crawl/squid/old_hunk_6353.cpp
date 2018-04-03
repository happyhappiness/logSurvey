    if (!visible && valid_id && dump_stat->owner_mask)
	visible = CBIT_TEST(*dump_stat->owner_mask, id);
    if (visible)
	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\t %d\n",
	    id, name, count, xdiv(count, dump_stat->busyDestroyedCount),
	    visible);
}

static void
