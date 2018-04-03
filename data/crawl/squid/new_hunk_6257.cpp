		percent(sfs.f_files - sfs.f_ffree, sfs.f_files));
	}
#endif
	storeAppendPrintf(sentry, "Flags:");
	if (SD->flags.selected)
	    storeAppendPrintf(sentry, " SELECTED");
	storeAppendPrintf(sentry, "\n");
    }
}

