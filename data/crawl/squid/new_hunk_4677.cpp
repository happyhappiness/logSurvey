}

// HTTP side sent us all virgin info
void ICAPModXact::noteBodyProductionEnded(BodyPipe &)
{
    ICAPXaction_Enter(noteBodyProductionEnded);

    Must(virgin.body_pipe->productionEnded());

    // push writer and sender in case we were waiting for the last-chunk
    writeMore();
