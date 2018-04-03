
std::ostream &Ipc::StartListeningCb::startPrint(std::ostream &os) const
{
    return os << "(FD " << fd << ", err=" << errNo;
}


void Ipc::StartListening(int sock_type, int proto, Ip::Address &addr,
                         int flags, FdNoteId fdNote, AsyncCall::Pointer &callback)
{
    OpenListenerParams p;
    p.sock_type = sock_type;
    p.proto = proto;
    p.addr = addr;
    p.flags = flags;
    p.fdNote = fdNote;

    if (UsingSmp()) { // if SMP is on, share
        Ipc::JoinSharedListen(p, callback);
        return; // wait for the call back
    }

    enter_suid();
    const int sock = comm_open_listener(p.sock_type, p.proto, p.addr, p.flags,
                                        FdNote(p.fdNote));
    const int errNo = (sock >= 0) ? 0 : errno;
    leave_suid();

    debugs(54, 3, HERE << "opened listen FD " << sock << " for " << p.addr);

    StartListeningCb *cbd =
        dynamic_cast<StartListeningCb*>(callback->getDialer());
    Must(cbd);
    cbd->fd = sock;
    cbd->errNo = errNo;
    ScheduleCallHere(callback);
}
