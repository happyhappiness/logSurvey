        buf.append(",notif", 6);

    if (theSessionFailures > 0)
        buf.Printf(",F%d", theSessionFailures);

    if (isSuspended)
        buf.append(",susp", 5);

    buf.append("]", 1);
    buf.terminate();
