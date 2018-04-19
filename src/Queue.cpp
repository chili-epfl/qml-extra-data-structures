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
 * @file AssociativeArray.cpp
 * @brief Source for a QML-enabled associative array, i.e QHash
 * @author Julien Grondier
 * @date 2018-04-19
 */


#include "Queue.h"


namespace QMLExtraDataStructures {
Queue::Queue(QQuickItem *parent) : QQuickItem(parent) {
    queue = QQueue<QVariant>();
}

void Queue::clear() {
    queue = QQueue<QVariant>();
}

QVariant Queue::dequeue() {
    if (!queue.isEmpty()) return queue.dequeue();
    return invalid;
}

void Queue::enqueue(QVariant const &t) {
    queue.enqueue(t);
}

QVariant Queue::head()
{
    if (!queue.isEmpty()) return queue.head();
    return invalid;
}

}
