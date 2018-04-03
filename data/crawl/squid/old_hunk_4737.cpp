    return commEof;
}

void ICAPXaction::mustStop(const char *aReason)
{
    Must(inCall); // otherwise nobody will call doStop()
    Must(!stopReason);
    Must(aReason);
    stopReason = aReason;
    debugs(93, 5, typeName << " will stop, reason: " << stopReason);
}

// internal cleanup
