    shut_down(0);
}

static void
cachemgrMenu(StoreEntry *sentry)
{
	action_table *a;
	for (a = ActionTable; a != NULL; a = a->next) {
		storeAppendPrintf(sentry, " %-22s\t%s\n", a->action, a->desc);
	}
}

static char *
