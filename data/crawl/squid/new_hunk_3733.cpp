// stop (or do not start) sending adapted message body
void Adaptation::Icap::ModXact::stopSending(bool nicely)
{
    debugs(93, 7, HERE << "Enter stop sending ");
    if (doneSending())
        return;
    debugs(93, 7, HERE << "Proceed with stop sending ");

    if (state.sending != State::sendingUndecided) {
        debugs(93, 7, HERE << "will no longer send" << status());
