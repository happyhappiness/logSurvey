		}

		fprintf (use_stdio == 1 ? stdout : stderr,
			 "PUTVAL %s interval=%.3f %s\n",
			 filename,
			 CDTIME_T_TO_DOUBLE (vl->interval),
			 values);
		return (0);
	}

