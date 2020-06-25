#include <math.h>
#include <stdio.h>

#include "Port.h"
#include "Constants.h"

EDPort::EDPort(EndDevice *ed, double rate) {
    this->ed = ed;
    this->rate = rate;

    _pforward = nullptr;
    _tforward = 0;
}

EDPort::~EDPort() {

}

void EDPort::receivePacket(Packet* packet) {
    ed->receivePacket(packet);
}

void EDPort::run(long long time) {
    if(_pforward != nullptr) {
        if(time >= _tforward) {
            // Forwarding finish
            sw_port->receivePacket(_pforward);
            _pforward = nullptr;
        }
    }
    if(_pforward == nullptr) {
        if(buffer.size() != 0) {
            // Dequeue packet and put to forwarding state
            _pforward = buffer.front();
            _tforward = time + (int)floor((double)_pforward->p_size / rate / us * 100.0d);
            //_pforward->send_time = _tforward; // send time from first switch
            buffer.pop();
        }
    }
}
