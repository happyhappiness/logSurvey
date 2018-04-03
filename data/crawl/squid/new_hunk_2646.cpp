}

void
IpcIoFile::handleNotification()
{
    debugs(47, 4, HERE << "notified");
    workerQueue->clearReaderSignal();
    handleResponses("after notification");
}

void
IpcIoFile::handleResponses(const char *when)
{
    debugs(47, 4, HERE << "popping all " << when);
    Must(workerQueue);
    IpcIoMsg ipcIo;
    // get all responses we can: since we are not pushing, this will stop
    while (workerQueue->pop(ipcIo))
        handleResponse(ipcIo);
}

void
IpcIoFile::handleResponse(const IpcIoMsg &ipcIo)
{
    const int requestId = ipcIo.requestId;
    debugs(47, 7, HERE << "popped disker response: " <<
        SipcIo(KidIdentifier, ipcIo, diskId)  << " at " << workerQueue->popQueue->size());

    Must(requestId);
    if (IpcIoPendingRequest *const pending = dequeueRequest(requestId)) {
        pending->completeIo(&ipcIo);
