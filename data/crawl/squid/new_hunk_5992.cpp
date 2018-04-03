	f->cputime);
    storeAppendPrintf(sentry, "wall_time = %f\n",
	tvSubDsec(f->timestamp, current_time));
    storeAppendPrintf(sentry, "swap.outs = %d\n",
	f->swap.outs);
    storeAppendPrintf(sentry, "swap.ins = %d\n",
	f->swap.ins);
    storeAppendPrintf(sentry, "swap.files_cleaned = %d\n",
	f->swap.files_cleaned);
    storeAppendPrintf(sentry, "aborted_requests = %d\n",
	f->aborted_requests);
}
