#pragma once

/**
 * interface of any dateunit component
 *
 * @todo implement +-Operator
 * @todo think about SIGN rule in the grammar file -> it can be possible that the sign will added to the number
 * so that the data calculation can deal with signed numbers
 * @todo for storing datunit objects, use a std::map in the ASTListener with an own comparator -> a good idea
 * for a unique key is an enum DAY, WEEK... -> create a suitable datatype for that
 * @todo think which data must be stored within a DateUnit object to do a calculation between two DateUnit objects
 * @todo think about how a set of DateUnit objects should be aggrgated to build the final value, take a look on C++11 Lambda Expression (http://de.cppreference.com/w/cpp/language/lambda) and C++ Operator overloading
 */
class IDateUnit
{
    /**
     * returns the id of the object
     */
    virtual void id() = 0;


};