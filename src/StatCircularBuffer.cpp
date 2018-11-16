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
 * @file StatCircularBuffer.h
 * @brief Source for a QML-enabled circular buffer with statistics calculations, e.g mean, stdev, min, max
 * @author Ayberk Özgür
 * @date 2018-10-16
 */

#include "StatCircularBuffer.h"

#include <QtMath>

#include <limits>

namespace QMLExtraDataStructures{

StatCircularBuffer::StatCircularBuffer(QQuickItem* parent) : CircularBuffer(parent){
    sum = 0;
    mean = 0;
    variance = 0;
    stdev = 0;
    min = std::numeric_limits<qreal>::infinity();
    max = -std::numeric_limits<qreal>::infinity();

    connect(this, SIGNAL(elementAdded(QVariant const&)), this, SLOT(addedCalc(QVariant const&)), Qt::DirectConnection);
    connect(this, SIGNAL(elementRemoved(QVariant const&)), this, SLOT(removedCalc(QVariant const&)), Qt::DirectConnection);
}

StatCircularBuffer::~StatCircularBuffer(){}

void StatCircularBuffer::addedCalc(QVariant const& element){
    bool ok = false;
    qreal elementReal = element.toReal(&ok);
    if(ok){
        sum += elementReal;

        qreal oldmean = mean;
        int N_plus_1 = buffer.size();
        mean = sum/N_plus_1;
        emit meanChanged();

        qreal oldvariance = variance;
        variance = N_plus_1 > 1 ? (elementReal*elementReal + (N_plus_1 - 1)*oldmean*oldmean - N_plus_1*mean*mean + (N_plus_1 - 2)*oldvariance)/(N_plus_1 - 1) : 0;
        stdev = qSqrt(variance);
        emit stdevChanged();

        if(elementReal > max){
            max = elementReal;
            emit maxChanged();
        }
        if(elementReal < min){
            min = elementReal;
            emit minChanged();
        }
    }
    else
        qCritical() << "StatCircularBuffer::addedCalc(): Added element cannot be converted to a qreal, StatCircularBuffer will not work!";
}

void StatCircularBuffer::removedCalc(QVariant const& element){
    bool ok = false;
    qreal elementReal = element.toReal(&ok);
    if(ok){
        sum -= elementReal;

        qreal oldmean = mean;
        int N_minus_1 = buffer.size();
        mean = N_minus_1 > 0 ? sum/N_minus_1 : 0;
        emit meanChanged();

        qreal oldvariance = variance;
        variance = N_minus_1 > 1 ? (-elementReal*elementReal + (N_minus_1 + 1)*oldmean*oldmean - N_minus_1*mean*mean + N_minus_1*oldvariance)/(N_minus_1 - 1) : 0;
        stdev = qSqrt(variance);
        emit stdevChanged();

        if(elementReal == min){
            min = std::numeric_limits<qreal>::infinity();
            for(QVariant e : buffer){
                qreal eReal = e.toReal(&ok);
                    if(ok && eReal < min)
                        min = eReal;
            }
            emit minChanged();
        }
        if(elementReal == max){
            max = -std::numeric_limits<qreal>::infinity();
            for(QVariant e : buffer){
                qreal eReal = e.toReal(&ok);
                    if(ok && eReal > max)
                        max = eReal;
            }
            emit maxChanged();
        }
    }
    else
        qCritical() << "StatCircularBuffer::removedCalc(): Removed element cannot be converted to a qreal, StatCircularBuffer will not work!";
}

}
