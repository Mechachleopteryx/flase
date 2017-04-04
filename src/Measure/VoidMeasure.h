

#ifndef _VOIDMEASURE_H
#define _VOIDMEASURE_H

#include <string>
#include <Measure.h>

#include "common.h"
#include "World.h"
#include "Sheep.h"


class VoidMeasure : public Measure
{
public:
    
    VoidMeasure( size_t skip );
    virtual ~VoidMeasure();

    virtual void measure( const World& world, const real time ) override;

    virtual void init();
    virtual real getMQD() { return mqdValue; }
    virtual real getMSD() { return msdValue; }

    virtual std::string getFile() { return file; }
};

#endif // _VOIDMEASURE_H