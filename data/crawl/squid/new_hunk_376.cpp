        handleRequestBodyProducerAborted();
}

bool
Client::abortOnData(const char *reason)
{
    abortAll(reason);
    return true;
}

// more origin request body data is available
void
Client::handleMoreRequestBodyAvailable()
