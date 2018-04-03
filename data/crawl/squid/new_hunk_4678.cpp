    ICAPXaction_Exit();
}

// body producer aborted
void ICAPModXact::noteBodyProducerAborted(BodyPipe &)
{
    ICAPXaction_Enter(noteBodyProducerAborted);

    mustStop("virgin HTTP body producer aborted");

    ICAPXaction_Exit();
}

// initiator aborted
void ICAPModXact::noteInitiatorAborted()
{
    ICAPXaction_Enter(noteInitiatorAborted);

    if (initiator) {
        cbdataReferenceDone(initiator);
        mustStop("initiator aborted");
    }

    ICAPXaction_Exit();
}

// adapted body consumer wants more adapted data and 
// possibly freed some buffer space
void ICAPModXact::noteMoreBodySpaceAvailable(BodyPipe &)
{
    ICAPXaction_Enter(noteMoreBodySpaceAvailable);

    if (state.sending == State::sendingVirgin)
        echoMore();
