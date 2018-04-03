        return;

    if (state.sending != State::sendingUndecided) {
        debugs(93, 7, "ICAPModXact will no longer send" << status());
        if (adapted.body_pipe != NULL) {
            virginBodySending.disable();
            // we may leave debts if we were echoing and the virgin
            // body_pipe got exhausted before we echoed all planned bytes
            const bool leftDebts = adapted.body_pipe->needsMoreData();
            stopProducingFor(adapted.body_pipe, nicely && !leftDebts);
        }
    } else {
        debugs(93, 7, "ICAPModXact will not start sending" << status());
        Must(!adapted.body_pipe);
    }

    state.sending = State::sendingDone;
    checkConsuming();
}

// should be called after certain state.writing or state.sending changes
void ICAPModXact::checkConsuming()
{
    // quit if we already stopped or are still using the pipe
    if (!virgin.body_pipe || !state.doneConsumingVirgin())
        return;

    debugs(93, 7, HERE << "will stop consuming" << status());
    stopConsumingFrom(virgin.body_pipe);
}

void ICAPModXact::parseMore()
