
    if (!doneSending() && state.sending != State::sendingUndecided)
        buf.Printf("S(%d)", state.sending);
}

void ICAPModXact::fillDoneStatus(MemBuf &buf) const
