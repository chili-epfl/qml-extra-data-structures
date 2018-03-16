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
 * @author Ayberk Özgür
 * @date 2017-04-21
 */

#include "AssociativeArray.h"

#include <QQmlEngine>

namespace QMLExtraDataStructures{

AssociativeArray::AssociativeArray(QQuickItem* parent) : QQuickItem(parent){
    array = QSharedPointer<QHash<QString, QVariant>>(new QHash<QString, QVariant>());
}

AssociativeArray::AssociativeArray(QSharedPointer<QHash<QString, QVariant>> existingArray, QQuickItem* parent) : QQuickItem(parent){
    array = existingArray;
}

AssociativeArray::~AssociativeArray(){}

AssociativeArray* AssociativeArray::copy(){
    AssociativeArray* copyArray = new AssociativeArray(array, parentItem());
    QQmlEngine::setObjectOwnership(copyArray, QQmlEngine::objectOwnership(this));
    return copyArray;
}

void AssociativeArray::clear(){
    array->clear();
}

QVariant AssociativeArray::get(QString const& key) const{
    return array->value(key, defaultValue);
}

void AssociativeArray::set(QString const& key, QVariant const& value){
    array->insert(key, value);
}

QList<QString> AssociativeArray::keys() const{
    return array->keys();
}

bool AssociativeArray::del(const QString &key) {

    if(array->contains(key)) {
        array->remove(key);
        return true;
    }

    return false;

}

}
