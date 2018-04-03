    ICAPXaction_Exit();
}

// adapted body consumer aborted
void ICAPModXact::noteBodyConsumerAborted(BodyPipe &)
{
    ICAPXaction_Enter(noteBodyConsumerAborted);

    mustStop("adapted body consumer aborted");

    ICAPXaction_Exit();
}

// internal cleanup
void ICAPModXact::swanSong()
{
    debugs(93, 5, HERE << "swan sings" << status());

    if (initiator) {
debugs(93, 2, HERE << "swan sings for " << stopReason << status());
        AsyncCall(93,5, initiator, ICAPInitiator::noteIcapHeadersAborted);
        cbdataReferenceDone(initiator);
    }

    stopWriting(false);
    stopBackup();
