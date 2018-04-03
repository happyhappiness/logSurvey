    }

    if (io.flag) {
        debugs(11, 1, "sentRequestBody error: FD " << io.fd << ": " << xstrerr(errno));
        ErrorState *err;
        err = errorCon(ERR_WRITE_ERROR, HTTP_BAD_GATEWAY, fwd->request);
        err->xerrno = errno;
        fwd->fail(err);
        abortTransaction("I/O error while sending request body");
        return;
