Ecap::XactionRep::swanSong()
{
    // clear body_pipes, if any

    if (theAnswerRep != NULL) {
		BodyPipe::Pointer body_pipe = answer().body_pipe;
		if (body_pipe != NULL && body_pipe->stillProducing(this))
			stopProducingFor(body_pipe, false);
	}

    {
		BodyPipe::Pointer body_pipe = theVirginRep.raw().body_pipe;
		if (body_pipe != NULL && body_pipe->stillConsuming(this))
			stopConsumingFrom(body_pipe);
	}

    terminateMaster();
    Adaptation::Initiate::swanSong();
}

void
Ecap::XactionRep::terminateMaster()
{
    if (theMaster) {
        AdapterXaction x = theMaster;
        theMaster.reset();
        x->stop();
	}
}

libecap::Message &
Ecap::XactionRep::virgin()
{
