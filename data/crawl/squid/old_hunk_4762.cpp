
#include "EventLoop.h"

EventLoop::EventLoop() : errcount(0), last_loop(false), timeService(NULL)
{}

void
EventLoop::prepareToRun()
{
