	}
    }
#endif /* RLIMIT_DATA */
#if HAVE_SETRLIMIT && defined(RLIMIT_VMEM)
    if (getrlimit(RLIMIT_VMEM, &rl) < 0) {
	debug(50, 0, "getrlimit: RLIMIT_VMEM: %s\n", xstrerror());
    } else {
	rl.rlim_cur = rl.rlim_max;	/* set it to the max */
	if (setrlimit(RLIMIT_VMEM, &rl) < 0) {
	    sprintf(tmp_error_buf, "setrlimit: RLIMIT_VMEM: %s", xstrerror());
	    fatal_dump(tmp_error_buf);
	}
    }
#endif /* RLIMIT_VMEM */
}

time_t