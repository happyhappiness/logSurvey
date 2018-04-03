    buf.append(" [", 2);

    if (makingVb)
        buf.Printf("M%d", static_cast<int>(makingVb));

    const BodyPipePointer &vp = theVirginRep.raw().body_pipe;
    if (!vp)
