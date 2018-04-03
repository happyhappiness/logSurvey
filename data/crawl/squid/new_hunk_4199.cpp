
const char *Ecap::XactionRep::status() const
{
    static MemBuf buf;
    buf.reset();

    buf.append(" [", 2);

    if (theAnswerRep != NULL) {
		MessageRep *answer = dynamic_cast<MessageRep*>(theAnswerRep.get());
		Must(answer);
		const BodyPipePointer &ap = answer->raw().body_pipe;
		if (ap != NULL && ap->stillProducing(this))
			buf.append("Ab ", 3);
        else
			buf.append("A. ", 3);
	}

    const BodyPipePointer &vp = theVirginRep.raw().body_pipe;
    if (vp != NULL && vp->stillConsuming(this))
		buf.append("Vb ", 3);
    else
		buf.append("V. ", 3);

    buf.Printf(" ecapx%d]", id);

    buf.terminate();

    return buf.content();
}
