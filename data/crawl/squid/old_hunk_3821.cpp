}

// adapted body consumer aborted
void ICAPModXact::noteBodyConsumerAborted(BodyPipe::Pointer)
{
    mustStop("adapted body consumer aborted");
}

// internal cleanup
void ICAPModXact::swanSong()
{
    debugs(93, 5, HERE << "swan sings" << status());

