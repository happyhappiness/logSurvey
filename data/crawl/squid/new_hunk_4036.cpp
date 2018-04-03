    abortTransaction("Virgin body too large.");
}

// TODO: when HttpStateData sends all errors to ICAP,
// we should be able to move this at the end of setVirginReply().
void
ServerStateData::adaptOrFinalizeReply()
