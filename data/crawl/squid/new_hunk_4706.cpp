                return;
            }
        }
    }

    HttpStateData::handleMoreRequestBodyAvailable();
}

// premature end of the request body
void
HttpStateData::handleRequestBodyProducerAborted()
{
    ServerStateData::handleRequestBodyProducerAborted();
    // XXX: SendComplete(COMM_ERR_CLOSING) does little. Is it enough?
    SendComplete(fd, NULL, 0, COMM_ERR_CLOSING, 0, this);
}

// called when we wrote request headers(!) or a part of the body
void
HttpStateData::sentRequestBody(int fd, size_t size, comm_err_t errflag)
{
    if (size > 0)
        kb_incr(&statCounter.server.http.kbytes_out, size);
    ServerStateData::sentRequestBody(fd, size, errflag);
}

// Quickly abort the transaction
// TODO: destruction should be sufficient as the destructor should cleanup,
// including canceling close handlers
void
HttpStateData::abortTransaction(const char *reason)
{
    debugs(11,5, HERE << "aborting transaction for " << reason <<
           "; FD " << fd << ", this " << this);
    if (fd >= 0)
        comm_close(fd);
    else
        delete this;
}

void
