HttpStateData::handleRequestBodyProducerAborted()
{
    ServerStateData::handleRequestBodyProducerAborted();
    abortTransaction("request body producer aborted");
}

// called when we wrote request headers(!) or a part of the body
