    return state.sending == State::sendingDone;
}

// stop (or do not start) sending adapted message body
void ICAPModXact::stopSending(bool nicely)
{
    if (doneSending())
