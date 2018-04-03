
    if (canIgnore && srcIntact && adapted) {
        debugs(85,3, HERE << "responding with older adapted msg");
        sendAnswer(Answer::Forward(theMsg));
        mustStop("sent older adapted msg");
        return;
    }
