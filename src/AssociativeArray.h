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
 * @file AssociativeArray.h
 * @brief Header for a QML-enabled associative array, i.e QHash
 * @author Ayberk Özgür
 * @date 2017-04-21
 */

#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

#include <QQuickItem>
#include <QHash>
#include <QSharedPointer>

class AssociativeArray : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */
    Q_PROPERTY(QVariant defaultValue MEMBER defaultValue)

public:

    /**
     * @brief Creates new associative array
     *
     * @param parent The QML parent
     */
    AssociativeArray(QQuickItem* parent = 0);

    /**
     * @brief Creates new associative array with existing internal array
     *
     * @param existingArray The existing internal array
     * @param parent The QML parent
     */
    AssociativeArray(QSharedPointer<QHash<QString, QVariant>> existingArray, QQuickItem* parent = 0);

    /**
     * @brief Destroys this associative array
     */
    ~AssociativeArray();

public slots:

    /**
     * @brief Returns a shallow copy of this object
     *
     * @return Shallow copy with the pointer to the same internal array
     */
    AssociativeArray* copy();

    /**
     * @brief Removes all key-value pairs from the array
     */
    void clear();

    /**
     * @brief Gets a value
     *
     * @param key Key associated with the value
     */
    QVariant get(QString const& key) const;

    /**
     * @brief Sets a key-value pair
     *
     * @param key The key
     * @param value The associated value
     */
    void set(QString const& key, QVariant const& value);

private:

    QSharedPointer<QHash<QString, QVariant>> array; ///< Pointer to the array containing the key-value pairs
    QVariant defaultValue;                          ///< The default value to return if a key is not found

};

Q_DECLARE_METATYPE(AssociativeArray*)

#endif // ASSOCIATIVEARRAY_H
