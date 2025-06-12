#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
    private:
        ATarget** _targetBook;
        int _countTargetBook;

        TargetGenerator(const TargetGenerator&);
        TargetGenerator& operator=(const TargetGenerator&);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};

#endif