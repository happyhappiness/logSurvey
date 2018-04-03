	}
	storeAppendPrintf(sentry, close_bracket);	/* } */
	storeAppendPrintf(sentry, "{Keep-Alive Ratio: %d%%}\n",
	    percent(e->stats.n_keepalives_recv, e->stats.n_keepalives_sent));
    }
    storeAppendPrintf(sentry, close_bracket);
}
