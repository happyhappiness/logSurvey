    Must(state.serviceWaiting);
    state.serviceWaiting = false;

    Must(service().up());

    startWriting();

    ICAPXaction_Exit();
}

void ICAPModXact::startWriting()
{
    state.writing = State::writingConnect;
    openConnection();
    // put nothing here as openConnection calls commConnectStart
    // and that may call us back without waiting for the next select loop
