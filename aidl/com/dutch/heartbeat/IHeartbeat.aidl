package com.dutch.heartbeat;

import com.dutch.heartbeat.IHeartbeatListener;

@VintfStability
interface IHeartbeat{
    String pulse();
    void setListener(in IHeartbeatListener listener);
}