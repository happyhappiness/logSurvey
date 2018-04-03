static void
refreshCountsStats(StoreEntry * sentry, struct RefreshCounts *rc)
{
    storeAppendPrintf(sentry, "\n\n%s histogram:\n", rc->proto);
    storeAppendPrintf(sentry, "Category\tCount\t%%Total\n");

    storeAppendPrintf(sentry, "revalidate_stale\t%6d\t%6.2f\n",
	rc->revalidate_stale, xpercent(rc->revalidate_stale, rc->total));
    storeAppendPrintf(sentry, "request_max_age_stale\t%6d\t%6.2f\n",
	rc->request_max_age_stale, xpercent(rc->request_max_age_stale, rc->total));
    storeAppendPrintf(sentry, "response_expires_stale\t%6d\t%6.2f\n",
	rc->response_expires_stale, xpercent(rc->response_expires_stale, rc->total));
    storeAppendPrintf(sentry, "response_expires_fresh\t%6d\t%6.2f\n",
	rc->response_expires_fresh, xpercent(rc->response_expires_fresh, rc->total));
    storeAppendPrintf(sentry, "conf_max_age_stale\t%6d\t%6.2f\n",
	rc->conf_max_age_stale, xpercent(rc->conf_max_age_stale, rc->total));
    storeAppendPrintf(sentry, "last_modified_factor_fresh\t%6d\t%6.2f\n",
	rc->last_modified_factor_fresh, xpercent(rc->last_modified_factor_fresh, rc->total));
    storeAppendPrintf(sentry, "last_modified_factor_stale\t%6d\t%6.2f\n",
	rc->last_modified_factor_stale, xpercent(rc->last_modified_factor_stale, rc->total));
    storeAppendPrintf(sentry, "conf_min_age_fresh\t%6d\t%6.2f\n",
	rc->conf_min_age_fresh, xpercent(rc->conf_min_age_fresh, rc->total));
    storeAppendPrintf(sentry, "default_stale\t%6d\t%6.2f\n",
	rc->default_stale, xpercent(rc->default_stale, rc->total));
    storeAppendPrintf(sentry, "total\t%6d\t%6.2f\n",
	rc->total, xpercent(rc->total, rc->total));
}

static void