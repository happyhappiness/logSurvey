            return;
        }

	/* XXX this may end up having to be transactionComplete() .. */
        ftpState->transactionAbort();
        return;
    }

