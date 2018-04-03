		int fd;

		mtime.sec = st.st_mtime;
		mtime.nsec = ST_MTIME_NSEC(st);
		if (stat(shallow, &st)) {
			if (mtime.sec)
				die("shallow file was removed during fetch");
		} else if (st.st_mtime != mtime.sec
#ifdef USE_NSEC
				|| ST_MTIME_NSEC(st) != mtime.nsec
#endif
			  )
			die("shallow file was changed during fetch");
