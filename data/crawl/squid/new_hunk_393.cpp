         * probably was aborted because content length exceeds one
         * of the maximum size limits.
         */
        abortOnData("entry aborted after calling appendSuccessHeader()");
        return;
    }

    if (master().userDataDone) {
        // Squid-to-client data transfer done. Abort data transfer on our
        // side to allow new commands from ftp client
        abortOnData("Squid-to-client data connection is closed");
        return;
    }

