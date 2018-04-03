    return needToProduce - haveAvailable;
}

bool
ConnStateData::closing() const
{
    return closing_;
}

/**
 * Called by ClientSocketContext to give the connection a chance to read
 * the entire body before closing the socket.
 */
void
ConnStateData::startClosing(const char *reason)
{
    debugs(33, 5, HERE << "startClosing " << this << " for " << reason);
    assert(!closing());
    closing_ = true;

    assert(bodyPipe != NULL);

    // We do not have to abort the body pipeline because we are going to
    // read the entire body anyway.
    // Perhaps an ICAP server wants to log the complete request.

    // If a consumer abort have caused this closing, we may get stuck
    // as nobody is consuming our data. Allow auto-consumption.
    bodyPipe->enableAutoConsumption();
}

void
