	Config.Timeout.read);
    storeAppendPrintf(sentry, "{DeferTimeout %d\n", Config.Timeout.defer);
    storeAppendPrintf(sentry, "{ClientLifetime %d\n", Config.Timeout.lifetime);
    /* Cachemgr.cgi expects an integer in the second field of the string */
    storeAppendPrintf(sentry,
	"{HttpAccelMode %d \"# Is operating as an HTTP accelerator\"}\n",
	Config2.Accel.on);
    storeAppendPrintf(sentry, close_bracket);
}

