/*
 * File:    Bools.h
 * 
 * This file is distributed under the MIT license. See "LICENSE" for text.
 * 
 * Author:  TaiyouKomazawa
 */

#ifndef BOOLS_H_
#define BOOLS_H_

#include <Arduino.h>

#include <stdint.h>

#include "MessageID.h"

#include "Structure.h"

class Bools : public StructMem
{
public:
    inline bool set(int bit, bool val){
        bitWrite(_data.val, i, val);
        return val;
    }
    
    inline bool get(int bit){
        return bitRead(_data.val, bit);
    }

    virtual inline int size(){ return MAX_BOOLS_SIZE; }
    virtual inline uint8_t *ptr(){ return _data.ptr; }

    virtual inline message_t msg_id(){
        return BOOLS;
    }

private:
    enum{
        MAX_BOOLS_SIZE = 1, //byte
    };

    typedef union _DataFrameType{
        uint8_t ptr[MAX_BOOLS_SIZE];
        struct{
            uint8_t val;
        };
    }_data_frame_t;

    _data_frame_t _data;
};

#endif
