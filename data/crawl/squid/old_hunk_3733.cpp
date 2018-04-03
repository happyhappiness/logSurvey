// stop (or do not start) sending adapted message body
void Adaptation::Icap::ModXact::stopSending(bool nicely)
{
    if (doneSending())
        return;

    if (state.sending != State::sendingUndecided) {
        debugs(93, 7, HERE << "will no longer send" << status());
