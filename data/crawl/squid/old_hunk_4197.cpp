    return rep->raw();
}

bool
Ecap::XactionRep::doneAll() const
{
    if (theMaster) {
        if (!doneWithAdapted() || sendingVirgin())
            return false;
	}   

    return Adaptation::Initiate::doneAll();
}

bool
Ecap::XactionRep::doneWithAdapted() const
{
    if (!theAnswerRep)
        return false;

    // we are not done if we are producing
    MessageRep *answer = dynamic_cast<MessageRep*>(theAnswerRep.get());
	Must(answer);
    const BodyPipePointer &ap = answer->raw().body_pipe;
    return !ap || !ap->stillProducing(this);
}

// are we still sending virgin body to theMaster?
bool
Ecap::XactionRep::sendingVirgin() const
{
    // we are sending if we are consuming
    const BodyPipePointer &vp = theVirginRep.raw().body_pipe;
    return vp != NULL && vp->stillConsuming(this);
}

// stops sending virgin to theMaster and enables auto-consumption
void
Ecap::XactionRep::dropVirgin(const char *reason)
{
    debugs(93,4, HERE << "because " << reason);

    BodyPipePointer &p = theVirginRep.raw().body_pipe;
    Must(p != NULL);
    Must(p->stillConsuming(this));
    stopConsumingFrom(p);
    p->enableAutoConsumption();
    if (doneWithAdapted())
        theMaster.reset();
}

void 
Ecap::XactionRep::useVirgin()
{
    debugs(93,3, HERE << status());

    // XXX: check state everywhere
    Must(!theAnswerRep);
    theMaster.reset();

	HttpMsg *answer = theVirginRep.raw().header->clone();
	Must(!theVirginRep.raw().body_pipe == !answer->body_pipe); // check clone()

	if (answer->body_pipe != NULL) {
        // if libecap consumed, we cannot shortcircuit
        Must(!answer->body_pipe->consumedSize());
        Must(answer->body_pipe->stillConsuming(this));
		stopConsumingFrom(answer->body_pipe);
    }

	sendAnswer(answer);
    Must(done());
}

void 
Ecap::XactionRep::useAdapted(const libecap::shared_ptr<libecap::Message> &m)
{
    debugs(93,3, HERE << status());
    theAnswerRep = m;
	MessageRep *rep = dynamic_cast<MessageRep*>(theAnswerRep.get());
	Must(rep);
	HttpMsg *answer = rep->raw().header;
    if (!theAnswerRep->body()) {
        if (!sendingVirgin())
            theMaster.reset();
        sendAnswer(answer);
	} else {
		Must(!answer->body_pipe); // only host can set body pipes
		rep->tieBody(this);
        debugs(93,4, HERE << "adapter will produce body" << status());
        theMaster->abMake(); // libecap will produce
        sendAnswer(answer);
    }
}

void
Ecap::XactionRep::vbIgnore()
{
    // if adapter does not need vb, we do not need to send it
    if (sendingVirgin())
        dropVirgin("vbIgnore");
}

void
Ecap::XactionRep::vbMake()
{
    Must(sendingVirgin());
    theMaster->noteVbContentAvailable(); // XXX: async
}

void
Ecap::XactionRep::vbStopMaking()
{
    // if adapter does not need vb, we do not need to send it
    if (sendingVirgin())
        dropVirgin("vbIgnore");
}

void
Ecap::XactionRep::vbMakeMore()
{
    Must(sendingVirgin() && !theVirginRep.raw().body_pipe->exhausted());
}

libecap::Area
Ecap::XactionRep::vbContent(libecap::off_type o, libecap::size_type s)
{
    const BodyPipePointer &p = theVirginRep.raw().body_pipe;
    const size_t haveSize = static_cast<size_t>(p->buf().contentSize()); // TODO: make MemBuf use size_t?

    // convert to Squid types; XXX: check for overflow
    const uint64_t offset = static_cast<uint64_t>(o);
