#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H
#include "colorplayer.h"
#include "messagequeue.h"
#include "QThread"

class DemuxThread:public QThread
{
public:
    static DemuxThread *Get()
    {
        static DemuxThread vt;
        return &vt;
    }
    void run();

    void initPlayerInfo(PlayerInfo *pPI);
    int initRawQueue(PlayerInfo *pPI);
    void queueMessage(MessageCmd_t MsgCmd);

    virtual ~DemuxThread();
private:
    DemuxThread();
    PlayerInfo *pPlayerInfo;
    message *pMessage;
};

#endif // DEMUXTHREAD_H
