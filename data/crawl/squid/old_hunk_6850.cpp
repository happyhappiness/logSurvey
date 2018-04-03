    storeAppendPrintf(sentry, "cpu_time = %f\n",
	f->cputime);
    storeAppendPrintf(sentry, "wall_time = %f\n",
        tvSubDsec(f->timestamp, current_time));
}

#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
