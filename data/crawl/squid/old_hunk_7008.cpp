		storeAppendPrintf(sentry, "!%s ", d->domain);
	}
	storeAppendPrintf(sentry, close_bracket);	/* } */
    }
    storeAppendPrintf(sentry, close_bracket);
}