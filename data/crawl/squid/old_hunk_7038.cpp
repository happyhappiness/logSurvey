	}
	gettimeofday(&now, NULL);
	if (now.tv_sec > last.tv_sec) {
		last = now;
		dt = (int) (now.tv_sec - start.tv_sec);
		printf ("T+ %6d: %9d req (%+4d), %4d conn, %3d/sec avg\n",
			dt,
			nrequests,
			reqpersec,
			nfds,
			(int) (nrequests / dt));
		reqpersec = 0;
	}
    }
    return 0;