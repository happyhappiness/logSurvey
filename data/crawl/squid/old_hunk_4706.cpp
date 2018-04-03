                return;
            }
        }

        /*
         * mb's content will be consumed in the SendRequestEntityWrapper
         * callback after comm_write is done.
         */
        flags.consume_body_data = 1;

        comm_write(fd, mb.content(), mb.contentSize(), SendRequestEntityWrapper, this, NULL);
    } else if (orig_request->body_reader == NULL) {
        /* Failed to get whole body, probably aborted */
        SendComplete(fd, NULL, 0, COMM_ERR_CLOSING, 0, this);
    } else if (orig_request->body_reader->remaining() == 0) {
        /* End of body */
        sendRequestEntityDone();
    } else {
        /* Failed to get whole body, probably aborted */
        SendComplete(fd, NULL, 0, COMM_ERR_CLOSING, 0, this);
    }
}

void
HttpStateData::SendRequestEntityWrapper(int fd, char *bufnotused, size_t size, comm_err_t errflag, int xerrno, void *data)
{
    HttpStateData *httpState = static_cast<HttpStateData *>(data);
    httpState->sendRequestEntity(fd, size, errflag);
}

void
HttpStateData::sendRequestEntity(int fd, size_t size, comm_err_t errflag)
{
    debug(11, 5) ("httpSendRequestEntity: FD %d: size %d: errflag %d.\n",
                  fd, (int) size, errflag);
    debugs(32,3,HERE << "httpSendRequestEntity called");

    /*
     * This used to be an assertion for body_reader != NULL.
     * Currently there are cases where body_reader may become NULL
     * before reaching this point in the code.  This can happen
     * because body_reader is attached to HttpRequest and other
     * modules (client_side, ICAP) have access to HttpRequest->body
     * reader.  An aborted transaction may cause body_reader to
     * become NULL between the time sendRequestEntity was registered
     * and actually called.  For now we'll abort the whole transaction,
     * but this should be fixed so that the client/icap/server sides
     * are cleaned up independently.
     */

    if (orig_request->body_reader == NULL) {
        debugs(32,1,HERE << "sendRequestEntity body_reader became NULL, aborting transaction");
        comm_close(fd);
        return;
    }

    if (size > 0) {
        fd_bytes(fd, size, FD_WRITE);
        kb_incr(&statCounter.server.all.kbytes_out, size);
        kb_incr(&statCounter.server.http.kbytes_out, size);

        if (flags.consume_body_data) {
            orig_request->body_reader->consume(size);
            orig_request->body_reader->bytes_read += size;
            debugs(32,3," HTTP server body bytes_read=" << orig_request->body_reader->bytes_read);
        }
    }

    if (errflag == COMM_ERR_CLOSING)
        return;

    if (errflag) {
        ErrorState *err;
        err = errorCon(ERR_WRITE_ERROR, HTTP_BAD_GATEWAY, fwd->request);
        err->xerrno = errno;
        fwd->fail(err);
        comm_close(fd);
        return;
    }

    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
        comm_close(fd);
        return;
    }

    size_t r = orig_request->body_reader->remaining();
    debugs(32,3,HERE << "body remaining = " << r);

    if (r) {
        debugs(32,3,HERE << "reading more body data");
        orig_request->body_reader->read(RequestBodyHandlerWrapper, this);
    } else {
        debugs(32,3,HERE << "done reading body data");
        sendRequestEntityDone();
    }
}

void
