void
ConnStateData::noteBodyConsumerAborted(BodyPipe::Pointer )
{
    if (!closing())
        startClosing("body consumer aborted");
}

/** general lifetime handler for HTTP requests */
