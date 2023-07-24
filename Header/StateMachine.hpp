#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

namespace Ekter
{
    typedef std::unique_ptr<State> StateRef;
    class StateMachine
    {
    public:
        StateMachine(){};
        ~StateMachine(){};
        void AddState(StateRef newState, bool isReplacing = true); // add new state to  the stack ,bool asks if u wanna remove the current state
        void RemoveState();
        void ProcessStateChanges();
        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;
        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}

#endif