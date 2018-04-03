    if (count)
	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
	    idx, (int) val, count,
	    xpercent(count, HeaderDestroyedCount));
}


