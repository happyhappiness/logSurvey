    Adaptation::Initiate::start();

    Must(theInitiator);
    launchXaction(false);
}

void Adaptation::Icap::Launcher::launchXaction(bool final)
{
    Must(!theXaction);
    ++theLaunches;
    debugs(93,4, HERE << "launching xaction #" << theLaunches);
    Adaptation::Icap::Xaction *x = createXaction();
    if (final)
        x->disableRetries();
    theXaction = initiateAdaptation(x);
    Must(theXaction);
}
