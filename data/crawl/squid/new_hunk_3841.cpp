}

// adapted body consumer aborted
void Adaptation::Icap::ModXact::noteBodyConsumerAborted(BodyPipe::Pointer)
{
    mustStop("adapted body consumer aborted");
}

// internal cleanup
void Adaptation::Icap::ModXact::swanSong()
{
    debugs(93, 5, HERE << "swan sings" << status());

