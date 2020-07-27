#ifndef CONSTANTS_H
#define CONSTANTS_H

const bool priority_queue_enable = false;
const bool time_reservation_enable = false;
const bool ats_enable = true;

const bool write_to_file = true;

const double us = 0.000001;
const double ms = 0.001;
const int byte = 8;
const int mega = 1000000;

const int SP_MODE = 0;
const int UBS_MODE = 1;

const double link_speed = 1000.d * (double)mega; // 1000Mbps
const int slot_duration = 5; // microsecond

const int TALKER_ATTRIBUTE = 0;
const int LISTENER_ACCEPT = 1;
const int LISTENER_REJECT = 2;

const int TSN_FLOW = 0;
const int AVB_FLOW = 1;
const int BE_FLOW = 2;

#endif
