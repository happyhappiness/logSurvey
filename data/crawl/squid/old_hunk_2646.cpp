}

void
IpcIoFile::handleResponses()
{
    Must(workerQueue);
    try {
        while (true) {
            IpcIoMsg ipcIo;
            workerQueue->pop(ipcIo); // XXX: notify disker?
            handleResponse(ipcIo);
        }
    } catch (const WorkerQueue::Empty &) {}
}

void
IpcIoFile::handleResponse(const IpcIoMsg &ipcIo)
{
    const int requestId = ipcIo.requestId;
    debugs(47, 7, HERE << "disker response to " << ipcIo.command <<
           "; ipcIo" << KidIdentifier << '.' << requestId);
    Must(requestId);
    if (IpcIoPendingRequest *const pending = dequeueRequest(requestId)) {
        pending->completeIo(&ipcIo);
