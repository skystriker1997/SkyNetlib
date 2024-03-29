#include <algorithm>
#include <memory>
#include "Macros.h"
#include "Poller.h"
#include <cstdio>
#include <thread>
#include <string>
#include <sstream>
#include "Logger.h"


#ifndef SKY_EVENTLOOP_H
#define SKY_EVENTLOOP_H


class EventLoop {
private:
    bool quit_;
    Logger logger_;
    std::unique_ptr<Poller> poller_;

public:
    DISALLOW_COPY_AND_MOVE(EventLoop);
    EventLoop();
    ~EventLoop();

    void Loop();

    int GetEpfd();

    void UpdateChannel(Channel* channel);
    void DeleteChannel(Channel* channel);

    bool CheckQuit() const;
    void Quit();

    long GetFdCount();
    bool FdCountLessThan(long n);

};

#endif
