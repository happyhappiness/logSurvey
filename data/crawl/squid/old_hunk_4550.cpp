        parseBody();
}

// note that allocation for echoing is done in handle204NoContent()
void ICAPModXact::maybeAllocateHttpMsg()
{
