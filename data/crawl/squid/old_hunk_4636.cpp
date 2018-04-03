        doneReading() && doneWriting();
}

void ICAPXaction::mustStop(const char *aReason)
{
    Must(inCall); // otherwise nobody will delete us if we are done()
    Must(aReason);
    if (!stopReason) {
        stopReason = aReason;
        debugs(93, 5, typeName << " will stop, reason: " << stopReason);
    } else {
        debugs(93, 5, typeName << " will stop, another reason: " << aReason);
    }
}

// This 'last chance' method is called before a 'done' transaction is deleted.
