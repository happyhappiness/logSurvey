void
Comm::ConnAcceptor::doAccept(int fd, void *data)
{
    debugs(5, 2, HERE << "New connection on FD " << fd);

    Must(isOpen(fd));
    ConnAcceptor *afd = static_cast<ConnAcceptor*>(data);

    if (!okToAccept()) {
        AcceptLimiter::Instance().defer(afd);
    } else {
        afd->acceptNext();
    }
    commSetSelect(fd, COMM_SELECT_READ, Comm::ConnAcceptor::doAccept, afd, 0);
}

bool