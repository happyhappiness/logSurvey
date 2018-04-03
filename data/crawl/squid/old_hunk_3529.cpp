// a short temporary string describing buffer status for debugging
const char *BodyPipe::status() const
{
    static MemBuf buf;
    buf.reset();

    buf.append(" [", 2);

    buf.Printf("%"PRIu64"<=%"PRIu64, theGetSize, thePutSize);
    if (theBodySize >= 0)
        buf.Printf("<=%"PRId64, theBodySize);
    else
        buf.append("<=?", 3);

    buf.Printf(" %d+%d", (int)theBuf.contentSize(), (int)theBuf.spaceSize());

    buf.Printf(" pipe%p", this);
    if (theProducer)
        buf.Printf(" prod%p", theProducer);
    if (theConsumer)
        buf.Printf(" cons%p", theConsumer);

    if (mustAutoConsume)
        buf.append(" A", 2);
    if (isCheckedOut)
        buf.append(" L", 2); // Locked

    buf.append("]", 1);

    buf.terminate();

    return buf.content();
}


