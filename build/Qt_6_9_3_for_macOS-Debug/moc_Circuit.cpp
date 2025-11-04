/****************************************************************************
** Meta object code from reading C++ file 'Circuit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Circuit.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Circuit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
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
struct qt_meta_tag_ZN7CircuitE_t {};
} // unnamed namespace

template <> constexpr inline auto Circuit::qt_create_metaobjectdata<qt_meta_tag_ZN7CircuitE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Circuit",
        "endGame",
        "",
        "mostRecentOutputUpdated",
        "DraggableButton*",
        "button",
        "input",
        "nodeDeleted",
        "evaluationAnimation",
        "QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>",
        "connections",
        "allConnections",
        "sendLevel",
        "inputs",
        "TruthTable*",
        "newTable",
        "sendEvaluation",
        "correct",
        "currentTable",
        "sendDescription",
        "registerGate",
        "onButtonMoved",
        "onDisconnectNode",
        "fromButton",
        "toButton",
        "onDeleteNode",
        "onClear",
        "toggleInputSignal",
        "inputButton",
        "levelUp",
        "level",
        "getInputButtonCount",
        "currentLevel",
        "onEvaluate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'endGame'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'mostRecentOutputUpdated'
        QtMocHelpers::SignalData<void(DraggableButton *, int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 }, { QMetaType::Int, 6 },
        }}),
        // Signal 'nodeDeleted'
        QtMocHelpers::SignalData<void(DraggableButton *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'evaluationAnimation'
        QtMocHelpers::SignalData<void(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> >)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'allConnections'
        QtMocHelpers::SignalData<void(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> >)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'sendLevel'
        QtMocHelpers::SignalData<void(int, TruthTable *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 }, { 0x80000000 | 14, 15 },
        }}),
        // Signal 'sendEvaluation'
        QtMocHelpers::SignalData<void(bool, TruthTable *)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 }, { 0x80000000 | 14, 18 },
        }}),
        // Signal 'sendDescription'
        QtMocHelpers::SignalData<void(QString)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'registerGate'
        QtMocHelpers::SlotData<void(DraggableButton *)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'onButtonMoved'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onDisconnectNode'
        QtMocHelpers::SlotData<void(DraggableButton *, DraggableButton *, int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 23 }, { 0x80000000 | 4, 24 }, { QMetaType::Int, 6 },
        }}),
        // Slot 'onDeleteNode'
        QtMocHelpers::SlotData<void(DraggableButton *)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'onClear'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleInputSignal'
        QtMocHelpers::SlotData<void(DraggableButton *)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 28 },
        }}),
        // Slot 'levelUp'
        QtMocHelpers::SlotData<void(int)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 30 },
        }}),
        // Slot 'getInputButtonCount'
        QtMocHelpers::SlotData<int(int)>(31, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::Int, 32 },
        }}),
        // Slot 'onEvaluate'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Circuit, qt_meta_tag_ZN7CircuitE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Circuit::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7CircuitE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7CircuitE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7CircuitE_t>.metaTypes,
    nullptr
} };

void Circuit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Circuit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->endGame(); break;
        case 1: _t->mostRecentOutputUpdated((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->nodeDeleted((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 3: _t->evaluationAnimation((*reinterpret_cast< std::add_pointer_t<QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>>>(_a[1]))); break;
        case 4: _t->allConnections((*reinterpret_cast< std::add_pointer_t<QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>>>(_a[1]))); break;
        case 5: _t->sendLevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<TruthTable*>>(_a[2]))); break;
        case 6: _t->sendEvaluation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<TruthTable*>>(_a[2]))); break;
        case 7: _t->sendDescription((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->registerGate((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 9: _t->onButtonMoved(); break;
        case 10: _t->onDisconnectNode((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->onDeleteNode((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 12: _t->onClear(); break;
        case 13: _t->toggleInputSignal((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 14: _t->levelUp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: { int _r = _t->getInputButtonCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->onEvaluate(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
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
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)()>(_a, &Circuit::endGame, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(DraggableButton * , int )>(_a, &Circuit::mostRecentOutputUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(DraggableButton * )>(_a, &Circuit::nodeDeleted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> > )>(_a, &Circuit::evaluationAnimation, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> > )>(_a, &Circuit::allConnections, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(int , TruthTable * )>(_a, &Circuit::sendLevel, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(bool , TruthTable * )>(_a, &Circuit::sendEvaluation, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Circuit::*)(QString )>(_a, &Circuit::sendDescription, 7))
            return;
    }
}

const QMetaObject *Circuit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Circuit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7CircuitE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Circuit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Circuit::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Circuit::mostRecentOutputUpdated(DraggableButton * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void Circuit::nodeDeleted(DraggableButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Circuit::evaluationAnimation(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> > _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void Circuit::allConnections(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> > _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Circuit::sendLevel(int _t1, TruthTable * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void Circuit::sendEvaluation(bool _t1, TruthTable * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void Circuit::sendDescription(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
