    if (theLaunches >= TheConfig.repeat_limit)
        x->disableRepeats("over icap_retry_limit");
    theXaction = initiateAdaptation(x);
    Must(initiated(theXaction));
}

void Adaptation::Icap::Launcher::noteAdaptationAnswer(HttpMsg *message)
