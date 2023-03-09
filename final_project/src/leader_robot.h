#ifndef __LEADER_AGENT__H
#define __LEADER_AGENT__H 

#include "enviro.h"

using namespace enviro;

class LeaderController : public Process, public AgentInterface {

    public:
    LeaderController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {
        goal_x = position().x;
        goal_y = position().y;
        emit(Event("goal_change", {
                { "x", goal_x },
                { "y", goal_y }
        }));

        if(sensor_value(0) < 70){
            track_velocity(0,15);
        } else {
            track_velocity(10,0);
        }

        Agent& other_robot = find_agent(1); 
        attach_to(other_robot);
    }
    void stop() {}

    double goal_x, goal_y;
};

class Leader : public Agent {
    public:
    Leader(json spec, World& world) : Agent(spec, world) {
        add_process(bc);
    }
    private:
    LeaderController bc;
};

DECLARE_INTERFACE(Leader)

#endif