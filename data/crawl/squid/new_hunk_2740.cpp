    mustStop("commClosed");
}

bool
Mgr::Inquirer::aggregate(Ipc::Response::Pointer aResponse)
{
    Mgr::Response& response = static_cast<Response&>(*aResponse);
    if (response.hasAction())
        aggrAction->add(response.getAction());
    return true;
}

void
Mgr::Inquirer::sendResponse()
{
    if (!strands.empty() && aggrAction->aggregatable()) {
        removeCloseHandler();
        AsyncJob::Start(new ActionWriter(aggrAction, fd));
        fd = -1; // should not close fd because we passed it to ActionWriter
    }
}

bool
Mgr::Inquirer::doneAll() const
{
    return !writer && Ipc::Inquirer::doneAll();
}

Ipc::StrandCoords
Mgr::Inquirer::applyQueryParams(const Ipc::StrandCoords& aStrands, const QueryParams& aParams)
{
    Ipc::StrandCoords strands;

    Mgr::Request *cause = static_cast<Mgr::Request *>(request.getRaw());
    QueryParam::Pointer processesParam = cause->params.queryParams.get("processes");
    QueryParam::Pointer workersParam = cause->params.queryParams.get("workers");

    if (processesParam == NULL || workersParam == NULL) {
        if (processesParam != NULL) {
