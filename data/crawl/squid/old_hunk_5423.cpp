    if (spec.restore_bps == -1)
	return;
    storeAppendPrintf(sentry, "\t\tCurrent: ");
    if (!buckets.size()) {
	storeAppendPrintf (sentry, "Not used yet.\n\n");
	return;
    }
    iterator pos = buckets.begin();
    while (pos != buckets.end()) {
	(*pos)->stats(sentry);
	++pos;
    }
    storeAppendPrintf(sentry, "\n\n");
}

