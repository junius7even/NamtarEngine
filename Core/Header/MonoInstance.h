//
// Created by Junius7 on 2023-08-30.
//

#ifndef NAMTARENGINE_MONOINSTANCE_H
#define NAMTARENGINE_MONOINSTANCE_H


class MonoInstance {
public:
    virtual ~MonoInstance()=default;
    MonoInstance(MonoInstance const &) = delete;
    MonoInstance const& operator=(MonoInstance const &) = delete;
private:

};


#endif //NAMTARENGINE_MONOINSTANCE_H
