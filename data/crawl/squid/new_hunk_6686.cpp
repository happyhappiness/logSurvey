{
    if (count)
	storeAppendPrintf(sentry, "\t%3d/%f\t%d\t%f\n",
	    idx, val, count, count / size);
}

void
