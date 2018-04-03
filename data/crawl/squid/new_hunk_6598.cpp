	    xpercent(f->stat.errCount, f->stat.parsCount),
	    xpercent(f->stat.repCount, f->stat.parsCount));
    }
    storeAppendPrintf(e, "\nSurvived/Parsed ratio: %d/%d (%.2f%%)\n", 
	HeaderEntrySurvivedCount, HeaderEntryParsedCount,
	xpercent(HeaderEntrySurvivedCount, HeaderEntryParsedCount));
}
