/*
 * Copyright (C) 2018 EPFL
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
 * @brief Header for a QML-enabled circular buffer with statistics calculations, e.g mean, stdev, min, max
 * @author Ayberk Özgür
 * @date 2018-10-16
 */

#ifndef STATCIRCULARBUFFER_H
#define STATCIRCULARBUFFER_H

#include <QQuickItem>
#include <QHash>
#include <QSharedPointer>

#include "CircularBuffer.h"

namespace QMLExtraDataStructures{

/**
 * @brief Limited size buffer that keeps the most recent N elements and calculates rolling means, standard deviations etc.
 */
class StatCircularBuffer : public CircularBuffer {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Mean of the array assuming that it is composed of real numbers, 0 otherwise */
    Q_PROPERTY(qreal mean READ getMean NOTIFY meanChanged)

    /** @brief Standard deviation of the array assuming it is composed of at least 2 real numbers, 0 otherwise */
    Q_PROPERTY(qreal stdev READ getStdev NOTIFY stdevChanged)

    /** @brief Minimum element in the array assuming it is composed of real numbers, infinity otherwise */
    Q_PROPERTY(qreal min READ getMin NOTIFY minChanged)

    /** @brief Maximum element in the array assuming it is composed of real numbers, -infinity otherwise */
    Q_PROPERTY(qreal max READ getMax NOTIFY maxChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates new statistics-enabled circular buffer
     *
     * @param parent The QML parent
     */
    StatCircularBuffer(QQuickItem* parent = 0);

    /**
     * @brief Destroys this buffer
     */
    ~StatCircularBuffer();

    /**
     * @brief Gets the current mean
     *
     * @return The current mean if it makes sense, 0 otherwise
     */
    qreal getMean() const { return mean; }

    /**
     * @brief Gets the current standard deviation
     *
     * @return The current standard deviation if it makes sense, 0 otherwise
     */
    qreal getStdev() const { return stdev; }

    /**
     * @brief Gets the current minimum element
     *
     * @return The current minimum element if it makes sense, infinity otherwise
     */
    qreal getMin() const { return min; }

    /**
     * @brief Gets the current maximum element
     *
     * @return The current maximum element if it makes sense, -infinity otherwise
     */
    qreal getMax() const { return max; }

    /** @endcond */

signals:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when the mean changes
     */
    void meanChanged();

    /**
     * @brief Emitted when the standard deviation changes
     */
    void stdevChanged();

    /**
     * @brief Emitted when the minimum element changes
     */
    void minChanged();

    /**
     * @brief Emitted when the maximum element changes
     */
    void maxChanged();

    /** @endcond */

private slots:

    /**
     * @brief Calculates new rolling values upon addition of a new element to the buffer
     *
     * @param element New element
     */
    void addedCalc(QVariant const& element);

    /**
     * @brief Calculates new rolling values upon removal of an element from the buffer
     *
     * @param element Removed element
     */
    void removedCalc(QVariant const& element);

private:

    qreal sum;      ///< Current sum of elements
    qreal mean;     ///< Current mean of elements
    qreal variance; ///< Current variance of elements
    qreal stdev;    ///< Current standard deviation of elements
    qreal min;      ///< Current minimum element
    qreal max;      ///< Current maximum element

};
}

Q_DECLARE_METATYPE(QMLExtraDataStructures::StatCircularBuffer*)

#endif // STATCIRCULARBUFFER_H
