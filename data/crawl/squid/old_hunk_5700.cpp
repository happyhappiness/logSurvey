	    fprintf(stderr, "ERROR: failed to release PAM authenticator\n");
	}
    }
    return (retval == PAM_SUCCESS ? 0 : 1);	/* indicate success */
}