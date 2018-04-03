    outputBuffer.Printf(" %d+%d", (int)theBuf.contentSize(), (int)theBuf.spaceSize());

    outputBuffer.Printf(" pipe%p", this);
    if (theProducer)
        outputBuffer.Printf(" prod%p", theProducer);
    if (theConsumer)
        outputBuffer.Printf(" cons%p", theConsumer);

    if (mustAutoConsume)
        outputBuffer.append(" A", 2);
