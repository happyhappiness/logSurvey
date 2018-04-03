    mustStop("initiator gone");
}

void Adaptation::Iterator::handleAdaptationBlock(const Answer &answer)
{
    debugs(93,5, HERE << "blocked by " << answer);
    clearAdaptation(theLauncher);
    updatePlan(false);
    sendAnswer(answer);
    mustStop("blocked");
}

void Adaptation::Iterator::handleAdaptationError(bool final)
{
    debugs(93,5, HERE << "final: " << final << " plan: " << thePlan);
    clearAdaptation(theLauncher);
