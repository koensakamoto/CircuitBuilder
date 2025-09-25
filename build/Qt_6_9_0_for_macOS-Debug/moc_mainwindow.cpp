/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "addButtonToCircuit",
        "",
        "DraggableButton*",
        "button",
        "GateType",
        "gateType",
        "nextLevel",
        "level",
        "gameOver",
        "disableEvaluate",
        "displayLevelDescription",
        "description",
        "startLevel",
        "onAndGateClicked",
        "onOrGateClicked",
        "onInverterClicked",
        "onNandGateClicked",
        "onNorGateClicked",
        "onXorGateClicked",
        "onXnorGateClicked",
        "onInputGateClicked",
        "onWireClicked",
        "checked",
        "onDeleteClicked",
        "onClearClicked",
        "updatePhysics",
        "drawWire",
        "QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>",
        "connections",
        "handleNodeDeleted",
        "getNextLevel",
        "levelComplete",
        "TruthTable*",
        "currentTable",
        "evaluationAnimation",
        "drawNewLevel",
        "inputs",
        "newTable",
        "on_startButton_clicked",
        "on_actionMENU_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'addButtonToCircuit'
        QtMocHelpers::SignalData<void(DraggableButton *, GateType)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'nextLevel'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'gameOver'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'disableEvaluate'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'displayLevelDescription'
        QtMocHelpers::SlotData<void(QString)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
        // Slot 'startLevel'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'onAndGateClicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onOrGateClicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onInverterClicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onNandGateClicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onNorGateClicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onXorGateClicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onXnorGateClicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onInputGateClicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onWireClicked'
        QtMocHelpers::SlotData<void(bool)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 23 },
        }}),
        // Slot 'onDeleteClicked'
        QtMocHelpers::SlotData<void(bool)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 23 },
        }}),
        // Slot 'onClearClicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updatePhysics'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'drawWire'
        QtMocHelpers::SlotData<void(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> >)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'handleNodeDeleted'
        QtMocHelpers::SlotData<void(DraggableButton *)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'getNextLevel'
        QtMocHelpers::SlotData<void(bool, TruthTable *)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 32 }, { 0x80000000 | 33, 34 },
        }}),
        // Slot 'evaluationAnimation'
        QtMocHelpers::SlotData<void(QMap<DraggableButton*,QVector<QPair<DraggableButton*,int>> >)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'drawNewLevel'
        QtMocHelpers::SlotData<void(int, TruthTable *)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 37 }, { 0x80000000 | 33, 38 },
        }}),
        // Slot 'on_startButton_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionMENU_triggered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addButtonToCircuit((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GateType>>(_a[2]))); break;
        case 1: _t->nextLevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->gameOver(); break;
        case 3: _t->disableEvaluate(); break;
        case 4: _t->displayLevelDescription((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->startLevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onAndGateClicked(); break;
        case 7: _t->onOrGateClicked(); break;
        case 8: _t->onInverterClicked(); break;
        case 9: _t->onNandGateClicked(); break;
        case 10: _t->onNorGateClicked(); break;
        case 11: _t->onXorGateClicked(); break;
        case 12: _t->onXnorGateClicked(); break;
        case 13: _t->onInputGateClicked(); break;
        case 14: _t->onWireClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->onDeleteClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->onClearClicked(); break;
        case 17: _t->updatePhysics(); break;
        case 18: _t->drawWire((*reinterpret_cast< std::add_pointer_t<QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>>>(_a[1]))); break;
        case 19: _t->handleNodeDeleted((*reinterpret_cast< std::add_pointer_t<DraggableButton*>>(_a[1]))); break;
        case 20: _t->getNextLevel((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<TruthTable*>>(_a[2]))); break;
        case 21: _t->evaluationAnimation((*reinterpret_cast< std::add_pointer_t<QMap<DraggableButton*,QList<std::pair<DraggableButton*,int>>>>>(_a[1]))); break;
        case 22: _t->drawNewLevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<TruthTable*>>(_a[2]))); break;
        case 23: _t->on_startButton_clicked(); break;
        case 24: _t->on_actionMENU_triggered(); break;
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
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< DraggableButton* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(DraggableButton * , GateType )>(_a, &MainWindow::addButtonToCircuit, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::nextLevel, 1))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addButtonToCircuit(DraggableButton * _t1, GateType _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void MainWindow::nextLevel(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
