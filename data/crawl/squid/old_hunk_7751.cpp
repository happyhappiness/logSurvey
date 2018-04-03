	    else
		storeAppendPrintf(sentry, "!%s ", d->domain);
	}
	storeAppendPrintf(sentry, "}\n");
    }
    storeAppendPrintf(sentry, "}\n");
}



void info_get(obj, sentry)
