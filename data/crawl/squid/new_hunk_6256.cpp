	f->cputime);
    storeAppendPrintf(sentry, "wall_time = %f\n",
	tvSubDsec(f->timestamp, current_time));
    storeAppendPrintf(sentry, "swap_files_cleaned = %d\n",
	f->swap_files_cleaned);
    storeAppendPrintf(sentry, "aborted_requests = %d\n",
	f->aborted_requests);
}
