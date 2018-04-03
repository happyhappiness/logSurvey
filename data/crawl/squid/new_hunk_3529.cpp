// a short temporary string describing buffer status for debugging
const char *BodyPipe::status() const
{
    static MemBuf outputBuffer;
    outputBuffer.reset();

    outputBuffer.append(" [", 2);

    outputBuffer.Printf("%"PRIu64"<=%"PRIu64, theGetSize, thePutSize);
    if (theBodySize >= 0)
        outputBuffer.Printf("<=%"PRId64, theBodySize);
    else
        outputBuffer.append("<=?", 3);

    outputBuffer.Printf(" %d+%d", (int)theBuf.contentSize(), (int)theBuf.spaceSize());

    outputBuffer.Printf(" pipe%p", this);
    if (theProducer)
        outputBuffer.Printf(" prod%p", theProducer);
    if (theConsumer)
        outputBuffer.Printf(" cons%p", theConsumer);

    if (mustAutoConsume)
        outputBuffer.append(" A", 2);
    if (isCheckedOut)
        outputBuffer.append(" L", 2); // Locked

    outputBuffer.append("]", 1);

    outputBuffer.terminate();

    return outputBuffer.content();
}


