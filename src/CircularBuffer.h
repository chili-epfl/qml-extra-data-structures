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
 * @file CircularBuffer.h
 * @brief Header for a QML-enabled circular buffer
 * @author Ayberk Özgür
 * @date 2017-04-30
 */

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QQuickItem>
#include <QHash>
#include <QSharedPointer>

namespace QMLExtraDataStructures{

/**
 * @brief Limited size buffer that keeps the most recent N elements
 */
class CircularBuffer : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Size of the buffer */
    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)

    /** @brief List of current elements */
    Q_PROPERTY(QVariantList elements READ getElements NOTIFY elementsChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates new circular buffer
     *
     * @param parent The QML parent
     */
    CircularBuffer(QQuickItem* parent = 0);

    /**
     * @brief Destroys this circular buffer array
     */
    ~CircularBuffer();

    /**
     * @brief Gets the current size of the buffer
     *
     * @return The size of the buffer, default is 1
     */
    int getSize() const { return size; }

    /**
     * @brief Sets the new size of the buffer
     *
     * @param newSize New size, must be greater than 0
     */
    void setSize(int newSize);

    /**
     * @brief Gets the copy of the current list of elements in the buffer
     *
     * @return Current list of elements in the buffer
     */
    QVariantList getElements() const { return buffer; }

    /** @endcond */

public slots:

    /**
     * @brief Removes all elements from the buffer
     */
    void clear();

    /**
     * @brief Gets the element at the given index, 0 is tail, size - 1 is head
     *
     * @param index The desired index
     *
     * @return The element at index, undefined if out of bounds
     */
    QVariant get(int index) const;

    /**
     * @brief Adds the given element to the head, removing an element from the tail if buffer is full
     *
     * @param element The element to add
     */
    void add(QVariant const& element);

    /**
     * @brief Removes the element at the given index
     *
     * @param index Index of the element to remove, does nothing if out of bounds
     */
    void remove(int index);

signals:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when the size of the buffer changes
     */
    void sizeChanged();

    /**
     * @brief Emitted when the current list of elements change
     */
    void elementsChanged();

    /** @endcond */

    /**
     * @brief Emitted when a new element is added
     *
     * @param element The newly added element
     */
    void elementAdded(QVariant const& element);

    /**
     * @brief Emitted when an element is removed, possibly due to buffer being full
     *
     * @param element The removed element
     */
    void elementRemoved(QVariant const& element);

protected:

    /** @cond DO_NOT_DOCUMENT */

    int size;               ///< Number of elements that can be contained in the buffer
    QVariantList buffer;    ///< Array containing the elements

    /** @endcond */

};
}

Q_DECLARE_METATYPE(QMLExtraDataStructures::CircularBuffer*)

#endif // CIRCULARBUFFER_H
