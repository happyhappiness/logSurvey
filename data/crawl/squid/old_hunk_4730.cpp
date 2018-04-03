    return virginBody.size() < TheBackupLimit;
}

// returns a temporary string depicting transaction status, for debugging
void ICAPModXact::fillPendingStatus(MemBuf &buf) const
{
    if (state.serviceWaiting)
        buf.append("U", 1);

    if (!state.doneWriting() && state.writing != State::writingInit)
        buf.Printf("w(%d)", state.writing);

