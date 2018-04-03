 * done later when enough sockets become available.
 */
void
Comm::ListenStateData::doAccept(int fd, void *data)
{
    debugs(5, 2, HERE << "New connection on FD " << fd);

    assert(isOpen(fd));
    ListenStateData *afd = static_cast<ListenStateData*>(data);

    if (!okToAccept()) {
        AcceptLimiter::Instance().defer(afd);
    } else {
        afd->acceptNext();
    }
    SetSelect(fd, COMM_SELECT_READ, Comm::ListenStateData::doAccept, afd, 0);
}

bool
Comm::ListenStateData::okToAccept()
{
    static time_t last_warn = 0;

