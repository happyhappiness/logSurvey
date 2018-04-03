
        // A non-recoverable error; notify the caller */
        debugs(5, 5, HERE << "non-recoverable error:" << status() << " handler Subscription: " << theCallSub);
        if (intendedForUserConnections())
            logAcceptError(newConnDetails);
        notify(flag, newConnDetails);
        mustStop("Listener socket closed");
        return;
