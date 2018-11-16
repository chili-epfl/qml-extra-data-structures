
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
 * @file Queue.h
 * @brief Header for a QML-enabled queue, i.e QQueue
 * @author Julien Grondier
 * @date 2018-04-19
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <QQuickItem>
#include <QQueue>


namespace QMLExtraDataStructures {
class Queue : public QQuickItem
{
    Q_OBJECT
public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates new queue
     *
     * @param parent The QML parent
     */

    Queue(QQuickItem* parent = 0);

public slots:


    /**
     * @brief Empties the queue
     */
    void clear();

    /**
     * @brief Removes the head item in the queue and returns it.
     *
     * @return The head of the queue. In case the queue is empty, it will return an invalid QVariant
     */

    QVariant dequeue();

    /**
     * @brief Adds value t to the tail of the queue.
     * @param t The value to add
     */

    void enqueue(QVariant const &t);

    /**
     * @brief Returns the queue's head item.
     * @return The head of the queue. In case the queue is empty, it will return nullptr
     */
    QVariant head();


private:

    QQueue<QVariant> queue;
    QVariant invalid = QVariant();

};
}
#endif // QUEUE_H

