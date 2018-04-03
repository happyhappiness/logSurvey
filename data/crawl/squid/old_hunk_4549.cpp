    return state.sending == State::sendingDone;
}

void ICAPModXact::stopSending(bool nicely)
{
    if (doneSending())
