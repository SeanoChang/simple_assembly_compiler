#ifndef EXECUTE_BEHAVIOR_H
#define EXECUTE_BEHAVIOR_H

class ExecuteBehavior {
    public:
        ExecuteBehavior();
        virtual ~ExecuteBehavior();
        virtual void execute() = 0;
}

#endif
