		c->result_hist[l],
		percent(c->result_hist[l], c->n_requests));
	}
	c = (ClientInfo *) hash_next(client_table);
    }
    storeAppendPrintf(sentry, close_bracket);