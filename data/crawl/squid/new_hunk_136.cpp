{
    debugs(9, 3, HERE);

    if (!Comm::IsConnOpen(ctrl.conn)) { /*Close handlers will cleanup*/
        debugs(9, 5, "The control connection to the remote end is closed");
        return;
    }

