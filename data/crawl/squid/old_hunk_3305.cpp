    if (!doneSending() && state.sending != State::sendingUndecided)
        buf.Printf("S(%d)", state.sending);

    if (canStartBypass)
        buf.append("Y", 1);

