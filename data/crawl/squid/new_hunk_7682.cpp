		    fatal(tmp_error_buf);
		}
	    }
	    for (k = 0; k < SWAP_DIRECTORIES_L2; k++) {
		sprintf(name, "%s/%02X/%02X", swappath(j), i, k);
		if (mkdir(name, 0755) < 0) {
		    if (errno != EEXIST) {
			sprintf(tmp_error_buf,
			    "Failed to make swap directory %s: %s",
			    name, xstrerror());
			fatal(tmp_error_buf);
		    }
		}
	    }
	}
    }
}
