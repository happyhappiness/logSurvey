        return;

    if (state.sending != State::sendingUndecided) {
        debugs(93, 7, "ICAPModXact will no longer send " << status());

        if (nicely)
            adapted->sendSourceFinish();
        else
            adapted->sendSourceAbort();
    } else {
        debugs(93, 7, "ICAPModXact will not start sending " << status());
        adapted->sendSourceAbort(); // or the sink may wait forever
    }

    state.sending = State::sendingDone;

    adapted = NULL; // refcounted
}

void ICAPModXact::stopReceiving()
{
    // stopSending NULLifies adapted but we do not NULLify virgin.
    // This is assymetric because we want to keep virgin->data even
    // though we are not expecting any more virgin->data->body.
    // TODO: can we cache just the needed headers info instead?

    // If they closed first, there is not point (or means) to notify them.

    if (state.doneReceiving)
        return;

    // There is no sendSinkFinished() to notify the other side.
    debugs(93, 7, "ICAPModXact will not receive " << status());

    state.doneReceiving = true;
}

void ICAPModXact::parseMore()
