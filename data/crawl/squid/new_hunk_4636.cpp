        doneReading() && doneWriting();
}

// initiator aborted
void ICAPXaction::noteInitiatorAborted()
{
    ICAPXaction_Enter(noteInitiatorAborted);

    if (theInitiator) {
        clearInitiator();
        mustStop("initiator aborted");
    }

    ICAPXaction_Exit();
}

// This 'last chance' method is called before a 'done' transaction is deleted.
