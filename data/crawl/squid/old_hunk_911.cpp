            mustStop("pconn race");
            return;
        }
    } else {

        al.icap.bytesRead+=io.size;

        updateTimeout();

        debugs(93, 3, HERE << "read " << io.size << " bytes");

        /*
         * See comments in Adaptation::Icap::Xaction.h about why we use commBuf
         * here instead of reading directly into readBuf.buf.
         */

        readBuf.append(commBuf, io.size);
        disableRetries(); // because pconn did not fail
    }

    handleCommRead(io.size);
