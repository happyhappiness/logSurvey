    icapReply = new HttpReply;
    icapReply->protoPrefix = "ICAP/"; // TODO: make an IcapReply class?

    debugs(93,7, "ICAPModXact initialized." << status());
}

// initiator wants us to start
void ICAPModXact::start()
{
    ICAPXaction_Enter(start);

    ICAPXaction::start();

    estimateVirginBody(); // before virgin disappears!

