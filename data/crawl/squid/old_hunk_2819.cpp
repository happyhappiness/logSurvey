    mustStop("initiator gone");
}

void Adaptation::Iterator::noteAdaptationQueryAbort(bool final)
{
    debugs(93,5, HERE << "final: " << final << " plan: " << thePlan);
    clearAdaptation(theLauncher);
