         * probably was aborted because content length exceeds one
         * of the maximum size limits.
         */
        abortAll("entry aborted after calling appendSuccessHeader()");
        return;
    }

