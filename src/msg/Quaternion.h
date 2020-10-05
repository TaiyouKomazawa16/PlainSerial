/*
 * File:    Quaternion.h
 * 
 * This file is distributed under the MIT license. See "LICENSE" for text.
 * 
 * Author:  TaiyouKomazawa
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_

#include <stdint.h>

#include "MessageID.h"

#include "Structure.h"

class Quaternion : public StructMem
{
public:
    Quaternion(float x = 0, float y = 0, float z = 0, float w=0)
    {
        set(x, y, z, w);
    }

    void set(float x, float y, float z, float w)
    {
        _data.x = x;
        _data.y = y;
        _data.z = z;
        _data.w = w;
    }

    inline float x(float x)
    {
        return _data.x = x;
    }
    inline float y(float y)
    {
        return _data.y = y;
    }
    inline float z(float z)
    {
        return _data.z = z;
    }
    inline float w(float w)
    {
        return _data.w = w;
    }

    inline float x()
    {
        return _data.x;
    }
    inline float y()
    {
        return _data.y;
    }
    inline float z()
    {
        return _data.z;
    }
    inline float w()
    {
        return _data.w;
    }

    virtual inline int size() { return MAX_P_QUATERNION_SIZE; }
    virtual inline uint8_t *ptr() { return _data.ptr; }

    virtual inline message_t msg_id()
    {
        return QUATERNION;
    }

private:
    enum
    {
        MAX_P_QUATERNION_SIZE = 16, //byte
    };

    typedef union _DataFrameType
    {
        uint8_t ptr[MAX_P_QUATERNION_SIZE];
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    } _data_frame_t;

    _data_frame_t _data;
};

#endif
