/****************************************************************************
** Meta object code from reading C++ file 'draggablebutton.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../Desktop/Dev2/cs3505-assignment9-sorenfanning/CircuitBuilder/draggablebutton.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draggablebutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15DraggableButtonE_t {};
} // unnamed namespace

template <> constexpr inline auto DraggableButton::qt_create_metaobjectdata<qt_meta_tag_ZN15DraggableButtonE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DraggableButton",
        "sendButton",
        "",
        "DraggableButton*",
        "button",
        "input",
        "deletingWire",
        "onButtonMoved",
        "deleteMe",
        "toggleSignal",
        "setWireMode",
        "isWireOn",
        "setDeleteMode",
        "isDelete",
        "input1Clicked",
        "input2Clicked",
        "outputClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sendButton'
        QtMocHelpers::SignalData<void(DraggableButton *, int, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 }, { QMetaType::Bool, 6 },
        }}),
        // Signal 'onButtonMoved'
        QtMocHelpers::SignalData<void(DraggableButton *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'deleteMe'
        QtMocHelpers::SignalData<void(DraggableButton *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'toggleSignal'
        QtMocHelpers::SignalData<void(DraggableButton *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'setWireMode'
        QtMocHelpers::SlotData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Slot 'setDeleteMode'
        QtMocHelpers::SlotData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
        // Slot 'input1Clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'input2Clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'outputClicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DraggableButton, qt_meta_tag_ZN15DraggableButtonE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DraggableButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DraggableButtonE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DraggableButtonE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15DraggableButtonE_t>.metaTypes,
    nullptr
} };

void DraggableButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DraggableButton *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sendButton((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 1: _t->onButtonMoved((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 2: _t->deleteMe((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 3: _t->toggleSignal((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 4: _t->setWireMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->setDeleteMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->input1Clicked(); break;
        case 7: _t->input2Clicked(); break;
        case 8: _t->outputClicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DraggableButton::*)(DraggableButton * , int , bool )>(_a, &DraggableButton::sendButton, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggableButton::*)(DraggableButton * )>(_a, &DraggableButton::onButtonMoved, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggableButton::*)(DraggableButton * )>(_a, &DraggableButton::deleteMe, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (DraggableButton::*)(DraggableButton * )>(_a, &DraggableButton::toggleSignal, 3))
            return;
    }
}

const QMetaObject *DraggableButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DraggableButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DraggableButtonE_t>.strings))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int DraggableButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DraggableButton::sendButton(DraggableButton * _t1, int _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void DraggableButton::onButtonMoved(DraggableButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void DraggableButton::deleteMe(DraggableButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void DraggableButton::toggleSignal(DraggableButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
