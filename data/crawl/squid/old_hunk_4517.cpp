    ICAPXaction_Exit();
}

// body producer aborted
void ICAPModXact::noteBodyProducerAborted(BodyPipe &)
{
    ICAPXaction_Enter(noteBodyProducerAborted);

    mustStop("virgin HTTP body producer aborted");

    ICAPXaction_Exit();
}
