    }

    if (virginBodyEndReached(virginBodySending)) {
        debugs(93, 5, "Adaptation::Icap::ModXact echoed all" << status());
        stopSending(true);
    } else {
        debugs(93, 5, "Adaptation::Icap::ModXact has " <<
               virgin.body_pipe->buf().contentSize() << " bytes " <<
               "and expects more to echo" << status());
        // TODO: timeout if virgin or adapted pipes are broken
    }
}

bool Adaptation::Icap::ModXact::doneSending() const
{
    return state.sending == State::sendingDone;
}

// stop (or do not start) sending adapted message body
void Adaptation::Icap::ModXact::stopSending(bool nicely)
{
    if (doneSending())
        return;

    if (state.sending != State::sendingUndecided) {
        debugs(93, 7, "Adaptation::Icap::ModXact will no longer send" << status());
        if (adapted.body_pipe != NULL) {
            virginBodySending.disable();
            // we may leave debts if we were echoing and the virgin
