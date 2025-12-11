package com.dutch.heartbeat;

@VintfStability
interface IHeartbeatListener {
    void onHeartbeat(long timestamp);
}