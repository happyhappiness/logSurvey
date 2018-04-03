    storeAppendPrintf(sentry, "\tNumber of queued ICP replies:\t%u\n",
                      statCounter.icp.replies_queued);

    storeAppendPrintf(sentry, "\tRequest failure ratio:\t%5.2f\n",
                      request_failure_ratio);

