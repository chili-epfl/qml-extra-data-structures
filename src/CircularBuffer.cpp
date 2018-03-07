/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file CircularBuffer.cpp
 * @brief Source for a QML-enabled circular buffer
 * @author Ayberk Özgür
 * @date 2017-04-30
 */

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(QQuickItem* parent) : QQuickItem(parent){
    size = 1;
}

CircularBuffer::~CircularBuffer(){}

void CircularBuffer::setSize(int newSize){
    if(newSize >= 1 && newSize != size){
        int prevBufferSize = buffer.size();

        while(newSize < buffer.size())
            emit elementRemoved(buffer.takeLast());
        size = newSize;
        emit sizeChanged();

        if(prevBufferSize != buffer.size())
            emit elementsChanged();
    }
}

void CircularBuffer::clear(){
    int prevBufferSize = buffer.size();

    while(buffer.size() > 0)
        emit elementRemoved(buffer.takeLast());

    if(prevBufferSize != buffer.size())
        emit elementsChanged();
}

QVariant CircularBuffer::get(int index) const {
    if(0 <= index && index < buffer.size())
        return buffer.at(index);
    else
        return QVariant();
}

void CircularBuffer::add(QVariant const& element){
    if(buffer.size() >= size)
        emit elementRemoved(buffer.takeLast());
    buffer.prepend(element);
    emit elementAdded(element);
    emit elementsChanged();
}

void CircularBuffer::remove(int index){
    if(0 <= index && index < buffer.size()){
        emit elementRemoved(buffer.takeAt(index));
        emit elementsChanged();
    }
}
