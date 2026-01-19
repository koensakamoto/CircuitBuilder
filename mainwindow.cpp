#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <QPainter>
#include <QActionGroup>
#include <QPushButton>
#include "draggablebutton.h"
#include <QMessageBox>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), circuit{Circuit(parent)}, draggableButtons{}
{
    ui->setupUi(this);

    // Apply modern, sleek dark theme with vibrant accents
    this->setStyleSheet(
        "QMainWindow {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #0f172a, stop:0.5 #1e293b, stop:1 #0f172a);"
        "}"
        "QWidget#centralwidget {"
        "   background: transparent;"
        "}"
        "QToolBar {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 rgba(30, 41, 59, 245), stop:1 rgba(15, 23, 42, 250));"
        "   border: none;"
        "   border-right: 1px solid rgba(56, 189, 248, 100);"
        "   spacing: 8px;"
        "   padding: 12px 6px;"
        "}"
        "QToolBar::separator {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 transparent, stop:0.3 rgba(56, 189, 248, 80),"
        "                                stop:0.5 rgba(56, 189, 248, 150), stop:0.7 rgba(56, 189, 248, 80), stop:1 transparent);"
        "   width: 2px;"
        "   margin: 10px 4px;"
        "}"
        "QToolBar QToolButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 rgba(51, 65, 85, 200), stop:1 rgba(30, 41, 59, 220));"
        "   border: 1px solid rgba(71, 85, 105, 150);"
        "   border-radius: 10px;"
        "   padding: 6px;"
        "   margin: 3px 2px;"
        "   min-width: 52px;"
        "   min-height: 52px;"
        "   max-width: 52px;"
        "   max-height: 52px;"
        "   color: #e2e8f0;"
        "   font-weight: bold;"
        "}"
        "QToolBar QToolButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 rgba(56, 189, 248, 60), stop:1 rgba(14, 165, 233, 80));"
        "   border: 1px solid rgba(56, 189, 248, 200);"
        "}"
        "QToolBar QToolButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 rgba(14, 165, 233, 150), stop:1 rgba(2, 132, 199, 180));"
        "   border: 1px solid #0ea5e9;"
        "}"
        "QToolBar QToolButton:checked {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 rgba(251, 191, 36, 200), stop:1 rgba(245, 158, 11, 220));"
        "   border: 2px solid #fbbf24;"
        "}"
        "QToolBar QToolButton:disabled {"
        "   background: rgba(51, 65, 85, 100);"
        "   border: 1px solid rgba(71, 85, 105, 80);"
        "   color: #64748b;"
        "}"
        "QStatusBar {"
        "   background: rgba(15, 23, 42, 240);"
        "   color: #94a3b8;"
        "   border-top: 1px solid rgba(56, 189, 248, 60);"
        "   padding: 6px 12px;"
        "   font-size: 10pt;"
        "   font-weight: 500;"
        "}"
        "QTextEdit {"
        "   background: rgba(30, 41, 59, 200);"
        "   border: 1px solid rgba(56, 189, 248, 100);"
        "   border-radius: 16px;"
        "   padding: 20px;"
        "   font-size: 14pt;"
        "   selection-background-color: rgba(56, 189, 248, 100);"
        "   color: #e2e8f0;"
        "}"
        "QMenuBar {"
        "   background: rgba(15, 23, 42, 250);"
        "   color: #e2e8f0;"
        "   border-bottom: 1px solid rgba(56, 189, 248, 60);"
        "   padding: 4px;"
        "}"
        "QMenuBar::item {"
        "   background: transparent;"
        "   padding: 6px 12px;"
        "   border-radius: 6px;"
        "}"
        "QMenuBar::item:selected {"
        "   background: rgba(56, 189, 248, 150);"
        "   color: white;"
        "}"
        "QMenu {"
        "   background: rgba(30, 41, 59, 250);"
        "   border: 1px solid rgba(56, 189, 248, 100);"
        "   border-radius: 8px;"
        "   padding: 8px 4px;"
        "}"
        "QMenu::item {"
        "   background: transparent;"
        "   padding: 8px 24px 8px 16px;"
        "   border-radius: 4px;"
        "   margin: 2px 4px;"
        "   color: #e2e8f0;"
        "}"
        "QMenu::item:selected {"
        "   background: rgba(56, 189, 248, 150);"
        "   color: white;"
        "}"
        "QMenu::separator {"
        "   height: 1px;"
        "   background: rgba(71, 85, 105, 150);"
        "   margin: 6px 12px;"
        "}"
        "QToolTip {"
        "   background: rgba(15, 23, 42, 250);"
        "   color: #e2e8f0;"
        "   border: 1px solid rgba(56, 189, 248, 150);"
        "   border-radius: 6px;"
        "   padding: 8px 12px;"
        "   font-size: 10pt;"
        "}"
    );

    ui->textEdit->setReadOnly(true);
    ui->previewTableWidget->hide();

    QAction* andGate = ui->actionAndGate;
    QAction* orGate = ui->actionOrGate;
    QAction* inverter = ui->actionInverter;
    QAction* clear = ui->actionClear;
    QAction* nandGate = ui->actionNandGate;
    QAction* norGate = ui->actionNorGate;
    QAction* xorGate = ui->actionXorGate;
    QAction* xnorGate = ui->actionXnorGate;
    QAction* inputGate = ui->actionInputGate;

    QActionGroup *group = new QActionGroup(this);

    group->addAction(andGate);
    group->addAction(orGate);
    group->addAction(nandGate);
    group->addAction(norGate);
    group->addAction(xorGate);
    group->addAction(xnorGate);
    group->addAction(inverter);
    group->addAction(clear);
    group->addAction(inputGate);

    // Set enhanced tooltips for better user experience
    ui->actionAndGate->setToolTip("<b>AND Gate</b><br/>Output is HIGH (1) only when ALL inputs are HIGH (1)<br/><i>Click to add to workspace</i>");
    ui->actionOrGate->setToolTip("<b>OR Gate</b><br/>Output is HIGH (1) when ANY input is HIGH (1)<br/><i>Click to add to workspace</i>");
    ui->actionInverter->setToolTip("<b>NOT Gate (Inverter)</b><br/>Inverts the input signal (0→1, 1→0)<br/><i>Click to add to workspace</i>");
    ui->actionNandGate->setToolTip("<b>NAND Gate</b><br/>Output is LOW (0) only when ALL inputs are HIGH (1)<br/><i>Click to add to workspace</i>");
    ui->actionNorGate->setToolTip("<b>NOR Gate</b><br/>Output is LOW (0) when ANY input is HIGH (1)<br/><i>Click to add to workspace</i>");
    ui->actionXorGate->setToolTip("<b>XOR Gate (Exclusive OR)</b><br/>Output is HIGH (1) when inputs are DIFFERENT<br/><i>Click to add to workspace</i>");
    ui->actionXnorGate->setToolTip("<b>XNOR Gate (Exclusive NOR)</b><br/>Output is HIGH (1) when inputs are SAME<br/><i>Click to add to workspace</i>");
    ui->actionWire->setToolTip("<b>Wire Mode</b><br/>Click to connect gates together<br/><i>Toggle ON/OFF</i>");
    ui->actionDelete->setToolTip("<b>Delete Mode</b><br/>Click gates to remove them<br/><i>Toggle ON/OFF</i>");
    ui->actionClear->setToolTip("<b>Clear All</b><br/>Remove all gates from workspace<br/><i>Use with caution!</i>");
    ui->actionInputGate->setToolTip("<b>Input Gate</b><br/>Circuit input node<br/><i>Click to add to workspace</i>");
    ui->actionMENU->setToolTip("<b>Main Menu</b><br/>Return to level selection<br/><i>Progress will be saved</i>");

    // Style special toolbar buttons to make them more intuitive

    QWidget* deleteWidget = ui->toolBar->widgetForAction(ui->actionDelete);
    if (deleteWidget) {
        deleteWidget->setStyleSheet(
            "QToolButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(239, 68, 68, 40), stop:1 rgba(220, 38, 38, 60));"
            "   border: 1px solid rgba(239, 68, 68, 150);"
            "   border-radius: 10px;"
            "   padding: 6px;"
            "   margin: 3px 2px;"
            "   min-width: 52px;"
            "   min-height: 52px;"
            "   max-width: 52px;"
            "   max-height: 52px;"
            "   color: #fca5a5;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(239, 68, 68, 100), stop:1 rgba(220, 38, 38, 120));"
            "   border: 1px solid rgba(248, 113, 113, 200);"
            "   color: #fecaca;"
            "}"
            "QToolButton:checked {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(239, 68, 68, 200), stop:1 rgba(220, 38, 38, 220));"
            "   border: 2px solid #ef4444;"
            "   color: white;"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(220, 38, 38, 180), stop:1 rgba(185, 28, 28, 200));"
            "}"
        );
    }


    QWidget* wireWidget = ui->toolBar->widgetForAction(ui->actionWire);
    if (wireWidget) {
        wireWidget->setStyleSheet(
            "QToolButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(34, 197, 94, 40), stop:1 rgba(22, 163, 74, 60));"
            "   border: 1px solid rgba(34, 197, 94, 150);"
            "   border-radius: 10px;"
            "   padding: 6px;"
            "   margin: 3px 2px;"
            "   min-width: 52px;"
            "   min-height: 52px;"
            "   max-width: 52px;"
            "   max-height: 52px;"
            "   color: #86efac;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(34, 197, 94, 100), stop:1 rgba(22, 163, 74, 120));"
            "   border: 1px solid rgba(74, 222, 128, 200);"
            "   color: #bbf7d0;"
            "}"
            "QToolButton:checked {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(34, 197, 94, 200), stop:1 rgba(22, 163, 74, 220));"
            "   border: 2px solid #22c55e;"
            "   color: white;"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(22, 163, 74, 180), stop:1 rgba(21, 128, 61, 200));"
            "}"
        );
    }

    disableToolBarActions();

    // Hide toolbar on initial welcome screen
    ui->toolBar->hide();

    // Hide tip description and preview table on welcome screen
    ui->tipDescription->hide();
    ui->previewTableWidget->hide();
    ui->truthTableTitle->hide();
    ui->truthTableContainer->hide();

    // Hide game control buttons on welcome screen
    ui->menuButton->hide();

    // Style the Menu button with sleek dark theme
    ui->menuButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(51, 65, 85, 200), stop:1 rgba(30, 41, 59, 220));"
        "   border: 1px solid rgba(148, 163, 184, 100);"
        "   border-radius: 10px;"
        "   color: #e2e8f0;"
        "   font-size: 11pt;"
        "   font-weight: bold;"
        "   padding: 8px 16px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(71, 85, 105, 200), stop:1 rgba(51, 65, 85, 220));"
        "   border: 1px solid rgba(56, 189, 248, 150);"
        "   color: #38bdf8;"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(30, 41, 59, 220), stop:1 rgba(15, 23, 42, 240));"
        "}"
    );

    // Set tooltip for the menu button
    ui->menuButton->setToolTip("Return to main menu");

    // Style Clear All button in toolbar with dark theme orange accent
    QWidget* clearWidget = ui->toolBar->widgetForAction(ui->actionClear);
    if (clearWidget) {
        clearWidget->setStyleSheet(
            "QToolButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(249, 115, 22, 40), stop:1 rgba(234, 88, 12, 60));"
            "   border: 1px solid rgba(249, 115, 22, 150);"
            "   border-radius: 10px;"
            "   padding: 6px;"
            "   margin: 3px 2px;"
            "   min-width: 52px;"
            "   min-height: 52px;"
            "   max-width: 52px;"
            "   max-height: 52px;"
            "   color: #fdba74;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(249, 115, 22, 100), stop:1 rgba(234, 88, 12, 120));"
            "   border: 1px solid rgba(251, 146, 60, 200);"
            "   color: #fed7aa;"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(234, 88, 12, 180), stop:1 rgba(194, 65, 12, 200));"
            "}"
        );
    }

    connect(&circuit, &Circuit::nodeDeleted, this, &MainWindow::handleNodeDeleted);

    connect(ui->EvaluateButton, &QPushButton::pressed, &circuit, &Circuit::onEvaluate);

    connect(ui->actionAndGate, &QAction::triggered, this, &MainWindow::onAndGateClicked);
    connect(ui->actionOrGate, &QAction::triggered, this, &MainWindow::onOrGateClicked);
    connect(ui->actionInverter, &QAction::triggered, this, &MainWindow::onInverterClicked);
    connect(ui->actionNandGate, &QAction::triggered, this, &MainWindow::onNandGateClicked);
    connect(ui->actionNorGate, &QAction::triggered, this, &MainWindow::onNorGateClicked);
    connect(ui->actionXorGate, &QAction::triggered, this, &MainWindow::onXorGateClicked);
    connect(ui->actionXnorGate, &QAction::triggered, this, &MainWindow::onXnorGateClicked);
    connect(ui->actionInputGate, &QAction::triggered, this, &MainWindow::onInputGateClicked);
    connect(&circuit, &Circuit::evaluationAnimation, this, &MainWindow::evaluationAnimation);

    connect(ui->actionWire, &QAction::triggered, this, &MainWindow::onWireClicked);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteClicked);

    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::onClearClicked);
    connect(ui->menuButton, &QPushButton::clicked, this, &MainWindow::returnToMenu);

    connect(this, &MainWindow::addButtonToCircuit, &circuit, &Circuit::addButton);

    connect(&circuit, &Circuit::allConnections, this, &MainWindow::drawWire);

    connect(&circuit, &Circuit::sendEvaluation, this, &MainWindow::getNextLevel);
    connect(this, &MainWindow::nextLevel, &circuit, &Circuit::levelUp);
    connect(&circuit, &Circuit::sendLevel, this, &MainWindow::drawNewLevel);
    connect(&circuit, &Circuit::sendDescription, this, &MainWindow::displayLevelDescription);
    connect(&circuit, &Circuit::endGame, this, &MainWindow::gameOver);



    // Physics set up
    initializePhysics();

    // Setup physics update timer
    physicsTimer = new QTimer(this);
    connect(physicsTimer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    physicsTimer->start(16); // 60 FPS approximately

    // Background label - fullscreen optimized with clean gradient
    backgroundGridLabel = new QLabel(ui->centralwidget);
    backgroundGridLabel->setGeometry(0, 0, 1440, 900);
    backgroundGridLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    backgroundGridLabel->setStyleSheet("background: transparent;");

    // Create clean gradient background (no wallpaper)
    backgroundPixmap = new QPixmap(1440, 900);
    backgroundPixmap->fill(Qt::transparent);

    // Bring others forward IF BUTTONS ARE NOT WORKING THIS COULD BE WHY
    ui->textEdit->raise();
    ui->startButton->raise();
    ui->EvaluateButton->raise();
    ui->EvaluateButton->hide();
    ui->gridLayoutWidget->raise();
    ui->menuButton->raise();

    // Center welcome screen elements after window is fully shown
    QTimer::singleShot(100, this, &MainWindow::centerWelcomeScreen);

    // Style the Start Button with glowing cyan accent
    ui->startButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(14, 165, 233, 180), stop:1 rgba(6, 182, 212, 200));"
        "   border: 2px solid rgba(56, 189, 248, 200);"
        "   border-radius: 16px;"
        "   color: white;"
        "   font-size: 16pt;"
        "   font-weight: bold;"
        "   padding: 12px 24px;"
        "   letter-spacing: 3px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(56, 189, 248, 200), stop:1 rgba(34, 211, 238, 220));"
        "   border: 2px solid rgba(103, 232, 249, 255);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(6, 182, 212, 200), stop:1 rgba(8, 145, 178, 220));"
        "   border: 2px solid rgba(14, 165, 233, 200);"
        "}"
    );


    for (int level = 1; level <= 12; level++) {
        QString buttonName = QString("ButtonLevel%1").arg(level);
        QPushButton* button = findChild<QPushButton*>(buttonName);
        if (button) {
            button->setStyleSheet(levelButtonStyle);
            connect(button, &QPushButton::clicked, this, [this, level]() {
                startLevel(level);
            });
        }
    }

    // Style the Evaluate Button with glowing green accent
    ui->EvaluateButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(16, 185, 129, 180), stop:1 rgba(5, 150, 105, 200));"
        "   color: white;"
        "   border: 2px solid rgba(52, 211, 153, 180);"
        "   border-radius: 14px;"
        "   padding: 12px 24px;"
        "   font-size: 14pt;"
        "   font-weight: bold;"
        "   letter-spacing: 1px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(52, 211, 153, 200), stop:1 rgba(16, 185, 129, 220));"
        "   border: 2px solid rgba(110, 231, 183, 255);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(5, 150, 105, 200), stop:1 rgba(4, 120, 87, 220));"
        "   border: 2px solid rgba(16, 185, 129, 180);"
        "}"
        "QPushButton:disabled {"
        "   background: rgba(51, 65, 85, 150);"
        "   border: 1px solid rgba(71, 85, 105, 100);"
        "   color: #64748b;"
        "}"
    );
    ui->EvaluateButton->setToolTip("Check if your circuit produces the correct truth table");

    // Style the tip description label with dark theme
    ui->tipDescription->setStyleSheet(
        "QLabel {"
        "   background: rgba(30, 41, 59, 220);"
        "   border: 1px solid rgba(56, 189, 248, 100);"
        "   border-radius: 10px;"
        "   padding: 10px 15px;"
        "   font-size: 10pt;"
        "   font-weight: 600;"
        "   color: #e2e8f0;"
        "   line-height: 1.4;"
        "}"
    );

    // Style the truth table title with dark theme cyan accent
    ui->truthTableTitle->setStyleSheet(
        "QLabel {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(14, 165, 233, 255), stop:0.5 rgba(6, 182, 212, 255), stop:1 rgba(8, 145, 178, 255));"
        "   color: #ffffff;"
        "   font-size: 13pt;"
        "   font-weight: 700;"
        "   letter-spacing: 2px;"
        "   border: 1px solid rgba(56, 189, 248, 80);"
        "   border-bottom: none;"
        "   padding: 10px;"
        "}"
    );

    // Style the truth table container - transparent to avoid gray artifacts
    ui->truthTableContainer->setStyleSheet(
        "QWidget {"
        "   background: transparent;"
        "   border: none;"
        "}"
    );

    // Status bar styling
    ui->statusbar->setStyleSheet(
        "QStatusBar {"
        "   font-size: 11pt;"
        "   padding: 8px 12px;"
        "   font-weight: 600;"
        "}"
        "QStatusBar::item {"
        "   border: none;"
        "}"
    );
}

MainWindow::~MainWindow() {
    if(physicsWorld){
        delete physicsWorld;
    }
    delete ui;
}

void MainWindow::onAndGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::AND_GATE, ui->actionAndGate->icon()));
}
void MainWindow::onOrGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::OR_GATE, ui->actionOrGate->icon()));
}
void MainWindow::onInverterClicked(){
    draggableButtons.push_back(createGateButton(GateType::INVERTER, ui->actionInverter->icon()));

}
void MainWindow::onNandGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::NAND_GATE, ui->actionNandGate->icon()));
}
void MainWindow::onNorGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::NOR_GATE, ui->actionNorGate->icon()));
}
void MainWindow::onXorGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::XOR_GATE, ui->actionXorGate->icon()));
}
void MainWindow::onXnorGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::XNOR_GATE, ui->actionXnorGate->icon()));
}
void MainWindow::onInputGateClicked(){
    draggableButtons.push_back(createGateButton(GateType::INPUT, ui->actionInputGate->icon()));
}

void MainWindow::createPhysicsBody(DraggableButton* button) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;

    QPoint ps = button->getPosition();
    bodyDef.position.Set(ps.x() / pixelsPerMeter, ps.y() / pixelsPerMeter);

    b2Body* body = physicsWorld->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(25.0f / pixelsPerMeter, 25.0f / pixelsPerMeter);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    fixtureDef.restitution = 0.0f;

    body->CreateFixture(&fixtureDef);
    button->setProperty("physicsBody", QVariant::fromValue((void*)body));
    button->setBody(body);
}

void MainWindow::initializePhysics() {
    physicsWorld = new b2World(b2Vec2(.0f, .0f));
}

void MainWindow::updatePhysics() {
    // Step the physics simulation
    physicsWorld->Step(1.0f/60.0f, 8, 3);  // Increase iteration counts

    // Update all buttons positions
    auto updateButtons = [this](const vector<DraggableButton*>& buttons) {
        for (auto button : buttons) {
            if (b2Body* body = (b2Body*)button->property("physicsBody").value<void*>()) {
                b2Vec2 position = body->GetPosition();

                // Convert physics coordinates to screen coordinates
                QPoint screenPos(position.x * pixelsPerMeter, position.y * pixelsPerMeter);
                button->setPosition(screenPos);
                button->setGeometry(screenPos.x(), screenPos.y(), GATE_SIZE, GATE_SIZE);
            }
        }
    };

    updateButtons(draggableButtons);
}

void MainWindow::onClearClicked() {
    // Update all buttons gravity
    for (auto button : draggableButtons) {
        button->buttonDelete();
    }
    QTimer::singleShot(3000, this, [this]() {draggableButtons.clear();});
    ui->statusbar->showMessage("Workspace cleared", 3000);
}

DraggableButton* MainWindow::createGateButton(const GateType gateType, const QIcon& icon) {
    Gate* gate = new Gate(gateType);
    DraggableButton* newButton = new DraggableButton(gateType, this, gate);

    emit addButtonToCircuit(newButton, gateType);

    QPoint globalMousePos = QCursor::pos() + QPoint(25,-17);
    QPoint widgetPos = this->mapFromGlobal(globalMousePos);
    newButton->setPosition(widgetPos);
    newButton->setGeometry(widgetPos.x(), widgetPos.y(), GATE_SIZE, GATE_SIZE);
    newButton->show();
    createPhysicsBody(newButton);

    newButton->setIconSize(QSize(GATE_SIZE, GATE_SIZE));
    newButton->setIcon(icon);

    connect(ui->actionWire, &QAction::triggered, newButton, &DraggableButton::setWireMode);
    connect(ui->actionDelete, &QAction::triggered, newButton, &DraggableButton::setDeleteMode);

    return newButton;
}

void MainWindow::drawWire(QMap<DraggableButton*, QVector<QPair<DraggableButton*, int>>> connections) {
    backgroundPixmap->fill(Qt::transparent);

    // Loop through each starting button and its wires
    for (DraggableButton* sourceButton : connections.keys()) {
        // Map button position to backgroundGridLabel coordinates using global mapping
        // Output port at (44, 21), center at (48, 25) for 8x8 port
        QPoint sourceGlobal = sourceButton->mapToGlobal(QPoint(48, 25));
        QPoint startPos = backgroundGridLabel->mapFromGlobal(sourceGlobal);

        // Loop over each connection for source button
        for (const auto& connection : connections.value(sourceButton)) {
            DraggableButton* targetButton = connection.first;
            int inputPort = connection.second;

            // Map target button position to backgroundGridLabel coordinates
            // For gates with 1 input (INVERTER, OUTPUT): input1 at (-2, 21), center = (2, 25 + 6)
            // For gates with 2 inputs: input1 at (-2, 9), input2 at (-2, 33)
            QPoint inputOffset;
            GateType targetGateType = targetButton->getGateType();

            if (targetGateType == GateType::INVERTER || targetGateType == GateType::OUTPUT) {
                // Single input gate - input is centered at (-2, 21), center at (2, 25)
                inputOffset = QPoint(2, 25);
            } else {
                // Two input gate
                switch (inputPort) {
                case 1: inputOffset = QPoint(2, 13); break;   // input1 top position center (9+4)
                case 2: inputOffset = QPoint(2, 37); break;   // input2 bottom position center (33+4)
                default: inputOffset = QPoint(2, 25); break;  // fallback center position
                }
            }
            QPoint targetGlobal = targetButton->mapToGlobal(inputOffset);
            QPoint endPos = backgroundGridLabel->mapFromGlobal(targetGlobal);

            // Handle backward wiring (when start is to the right of end)
            if (startPos.x() > endPos.x()) {
                int verticalOffset = GATE_SIZE;
                // See if it closer to go up or down
                if (startPos.y() + GATE_SIZE < endPos.y()) {
                    verticalOffset = -verticalOffset;
                }

                // Draw first segment (short horizontal from output)
                QPoint p1(startPos.x() + 20, startPos.y());
                drawWireArrow(startPos, p1, false);

                // Draw second segment (vertical)
                QPoint p2(p1.x(), p1.y() - verticalOffset);
                drawWireArrow(p1, p2, false);

                // Draw third and fourth segments
                QPoint p3(endPos.x() - 20, endPos.y());
                QPoint p4(p3.x(), p3.y() - verticalOffset);
                drawWireArrow(p4, p3, false);
                drawWireArrow(p3, endPos, false);

                // Updated position to draw connecting 3 wires
                endPos = p4;
                startPos = p2;
            }

                int midX = (startPos.x() + endPos.x()) / 2;
                QPoint p1(midX, startPos.y());
                QPoint p2(midX, endPos.y());

                drawWireArrow(startPos, p1, false);
                drawWireArrow(p1, p2, false);
                drawWireArrow(p2, endPos, false);

        }
    }

    backgroundGridLabel->setPixmap(*backgroundPixmap);
}

void MainWindow::drawWireArrow(QPoint start,  QPoint end, bool animating) {
    int arrowSize = 8;

    QPainter painter(backgroundPixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Define wire colors for dark theme
    QColor wireColor(148, 163, 184);    // Slate-400 for normal wires (visible on dark bg)
    QColor wireColorAnim(56, 189, 248); // Sky-400 for animated wires
    QColor arrowColor(100, 116, 139);   // Slate-500 for arrows
    QColor arrowColorAnim(34, 211, 238); // Cyan-400 for animated arrows

    if(animating){
        // Animated wire with glow effect
        QPen glowPen(QColor(56, 189, 248, 80), 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(glowPen);
        painter.drawLine(start, end);
        painter.setPen(QPen(wireColorAnim, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    } else {
        painter.setPen(QPen(wireColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }

    painter.drawLine(start, end);

    QPoint diff = end - start;
    QPoint arrowPos = (start + end) / 2;  // Place arrow in middle of segment

    QPolygon triangle;
    if (abs(diff.x()) > abs(diff.y())) {  // Horizontal line
        if (diff.x() > 0) {  // Going right
            triangle << arrowPos
                     << QPoint(arrowPos.x() - arrowSize, arrowPos.y() - arrowSize/2)
                     << QPoint(arrowPos.x() - arrowSize, arrowPos.y() + arrowSize/2);
        } else {  // Going left
            triangle << arrowPos
                     << QPoint(arrowPos.x() + arrowSize, arrowPos.y() - arrowSize/2)
                     << QPoint(arrowPos.x() + arrowSize, arrowPos.y() + arrowSize/2);
        }
    } else {  // Vertical line
        if (diff.y() > 0) {  // Going down
            triangle << arrowPos
                     << QPoint(arrowPos.x() - arrowSize/2, arrowPos.y() - arrowSize)
                     << QPoint(arrowPos.x() + arrowSize/2, arrowPos.y() - arrowSize);
        } else {  // Going up
            triangle << arrowPos
                     << QPoint(arrowPos.x() - arrowSize/2, arrowPos.y() + arrowSize)
                     << QPoint(arrowPos.x() + arrowSize/2, arrowPos.y() + arrowSize);
        }
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(animating ? arrowColorAnim : arrowColor));
    painter.drawPolygon(triangle);
}


void MainWindow::onWireClicked(bool checked) {
    if (checked) {
        disableToolBarActions();
        ui->actionWire->setEnabled(true);
        ui->statusbar->showMessage("Wire Mode: Click output ports then input ports to connect gates", 0);
    }
    else {
        enableToolBarActions();
        ui->statusbar->showMessage("Wire mode deactivated", 2000);
    }
}

void MainWindow::onDeleteClicked(bool checked){
    if (checked){
        disableToolBarActions();
        ui->actionDelete->setEnabled(true);
        ui->statusbar->showMessage("Delete Mode: Click gates or connection ports to remove them", 0);
    }

    else {
        enableToolBarActions();
        ui->statusbar->showMessage("Delete mode deactivated", 2000);
    }
}


void MainWindow::handleNodeDeleted(DraggableButton* button) {
    // Remove from vector
    draggableButtons.erase(
        std::remove(draggableButtons.begin(), draggableButtons.end(), button),
        draggableButtons.end()
    );
}

void MainWindow::startGame() {
    enableToolBarActions();

    // Show toolbar when game starts
    ui->toolBar->show();

    // Show menu button
    ui->menuButton->show();

    // fix zoom
    backgroundPixmap = new QPixmap(backgroundGridLabel->size());
    backgroundGridLabel->setScaledContents(false);

    // Draw subtle grid pattern on workspace
    backgroundPixmap->fill(Qt::transparent);
    QPainter gridPainter(backgroundPixmap);
    gridPainter.setRenderHint(QPainter::Antialiasing, true);

    // Subtle grid lines for dark theme
    QPen gridPen(QColor(71, 85, 105, 30), 1);  // Slate-600 with low opacity
    gridPainter.setPen(gridPen);

    int gridSize = 50;
    for (int x = 0; x < backgroundPixmap->width(); x += gridSize) {
        gridPainter.drawLine(x, 0, x, backgroundPixmap->height());
    }
    for (int y = 0; y < backgroundPixmap->height(); y += gridSize) {
        gridPainter.drawLine(0, y, backgroundPixmap->width(), y);
    }

    // Slightly stronger lines every 4 cells
    QPen majorGridPen(QColor(71, 85, 105, 50), 1);
    gridPainter.setPen(majorGridPen);
    for (int x = 0; x < backgroundPixmap->width(); x += gridSize * 4) {
        gridPainter.drawLine(x, 0, x, backgroundPixmap->height());
    }
    for (int y = 0; y < backgroundPixmap->height(); y += gridSize * 4) {
        gridPainter.drawLine(0, y, backgroundPixmap->width(), y);
    }

    backgroundGridLabel->setPixmap(*backgroundPixmap);

    ui->startButton->hide();
    ui->gridLayoutWidget->hide();

    ui->textEdit->hide();

    ui->statusbar->showMessage(QString("Level %1 - Build your circuit using the toolbar").arg(currentLevel + 1), 5000);

    emit nextLevel(currentLevel);

}
void MainWindow::startLevel(int level)
{
    qDebug() << "Starting level:" << level;
    currentLevel = level-1;
    startGame();

}


void MainWindow::enableToolBarActions() {
    ui->actionAndGate->setEnabled(true);
    ui->actionOrGate->setEnabled(true);
    ui->actionNorGate->setEnabled(true);
    ui->actionXorGate->setEnabled(true);
    ui->actionXnorGate->setEnabled(true);
    ui->actionNandGate->setEnabled(true);
    ui->actionInverter->setEnabled(true);
    ui->actionWire->setEnabled(true);
    ui->actionDelete->setEnabled(true);
    ui->actionInputGate->setEnabled(true);

    // Always keep CLEAR ALL enabled
    ui->actionClear->setEnabled(true);
}

void MainWindow::disableToolBarActions() {
    ui->actionAndGate->setEnabled(false);
    ui->actionOrGate->setEnabled(false);
    ui->actionNorGate->setEnabled(false);
    ui->actionXorGate->setEnabled(false);
    ui->actionXnorGate->setEnabled(false);
    ui->actionNandGate->setEnabled(false);
    ui->actionInverter->setEnabled(false);
    ui->actionWire->setEnabled(false);
    ui->actionDelete->setEnabled(false);
    ui->actionInputGate->setEnabled(false);

    // Always keep CLEAR ALL enabled
    ui->actionClear->setEnabled(true);
}

void MainWindow::drawNewLevel(int inputs, TruthTable* newTable) {
    ui->actionWire->setChecked(false);
    ui->actionDelete->setChecked(false);
    enableToolBarActions();

    QPoint p;

    backgroundPixmap->fill(Qt::transparent);
    backgroundGridLabel->setPixmap(*backgroundPixmap);

    // Calculate vertical spacing for input gates - positioned in lower half of screen
    int verticalSpacing = 120;  // Space between input gates
    int startY = 450;  // Starting Y position (below truth table area)

    // If we have many inputs, adjust spacing to fit better
    if (inputs > 3) {
        verticalSpacing = 90;
        startY = 420;
    }

    // Calculate the vertical center of all input gates
    int totalInputHeight = (inputs - 1) * verticalSpacing;
    int inputCenterY = startY + (totalInputHeight / 2);

    // Output gate positioned at vertical center of lower half
    int outputY = 520;  // Center of lower workspace area

    // Create input gates with enhanced styling
    for (int i = 0; i < inputs; i++){
        DraggableButton* input = createGateButton(GateType::INPUT, ui->actionInputGate->icon());
        p = QPoint(150, startY + (i * verticalSpacing));
        input->move(p);

        // Style input gates with dark theme
        input->setStyleSheet(
            "DraggableButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 rgba(56, 189, 248, 150), stop:1 rgba(14, 165, 233, 180));"
            "   border: 2px solid rgba(56, 189, 248, 200);"
            "   border-radius: 8px;"
            "}"
            "DraggableButton:hover {"
            "   border: 2px solid rgba(251, 191, 36, 200);"
            "}"
        );

        // Re-apply port button style after parent styling
        QPushButton* outputPort = input->findChild<QPushButton*>("portOutput");
        if (outputPort) {
            outputPort->setFixedSize(8, 8);
            outputPort->setStyleSheet(
                "QPushButton {"
                "   background: #1e293b;"
                "   border: 1px solid #34d399;"
                "   border-radius: 4px;"
                "   min-width: 8px; max-width: 8px;"
                "   min-height: 8px; max-height: 8px;"
                "}"
                "QPushButton:hover { background: #34d399; }"
            );
        }

        inputOutputButtons.push_back(input);
    }

    // Create output gate with enhanced styling - centered vertically on screen
    p = QPoint(850, outputY);
    DraggableButton* output = createGateButton(GateType::OUTPUT, ui->actionInputGate->icon());
    output->move(p);

    // Style output gate with dark theme green accent
    output->setStyleSheet(
        "DraggableButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(52, 211, 153, 150), stop:1 rgba(16, 185, 129, 180));"
        "   border: 2px solid rgba(52, 211, 153, 200);"
        "   border-radius: 8px;"
        "}"
        "DraggableButton:hover {"
        "   border: 2px solid rgba(251, 191, 36, 200);"
        "}"
    );

    // Re-apply port button style after parent styling
    QPushButton* inputPort = output->findChild<QPushButton*>("portInput1");
    if (inputPort) {
        inputPort->setFixedSize(8, 8);
        inputPort->setStyleSheet(
            "QPushButton {"
            "   background: #1e293b;"
            "   border: 1px solid #38bdf8;"
            "   border-radius: 4px;"
            "   min-width: 8px; max-width: 8px;"
            "   min-height: 8px; max-height: 8px;"
            "}"
            "QPushButton:hover { background: #38bdf8; }"
        );
    }

    inputOutputButtons.push_back(output);
    // Pull data out of truthtable
    QTableWidget* tableWidget = ui->previewTableWidget;
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->verticalHeader()->setVisible(false);  // Hide row numbers
    tableWidget->setShowGrid(true);
    tableWidget->setFrameShape(QFrame::NoFrame);  // Remove frame border
    tableWidget->setCornerButtonEnabled(false);  // Disable corner button
    tableWidget->horizontalHeader()->setHighlightSections(false);  // No highlight

    // Dark theme truth table design - no border radius to avoid gray corners
    tableWidget->setStyleSheet(
        "QTableWidget {"
        "   background: rgba(30, 41, 59, 255);"
        "   border: 1px solid rgba(56, 189, 248, 80);"
        "   border-top: none;"
        "   gridline-color: rgba(71, 85, 105, 100);"
        "   font-size: 14pt;"
        "   font-weight: 600;"
        "   selection-background-color: transparent;"
        "   font-family: 'Segoe UI', 'SF Pro Display', Arial, sans-serif;"
        "   outline: none;"
        "}"
        "QTableWidget::item {"
        "   padding: 14px 20px;"
        "   border: none;"
        "   border-bottom: 1px solid rgba(71, 85, 105, 80);"
        "   border-right: 1px solid rgba(71, 85, 105, 60);"
        "   color: #e2e8f0;"
        "}"
        "QTableWidget::item:selected {"
        "   background: transparent;"
        "}"
        "QTableWidget QTableCornerButton::section {"
        "   background: rgba(30, 41, 59, 255);"
        "   border: none;"
        "}"
        "QHeaderView {"
        "   border: none;"
        "   outline: none;"
        "   background: transparent;"
        "}"
        "QHeaderView::section {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(14, 165, 233, 255), stop:0.5 rgba(6, 182, 212, 255), stop:1 rgba(8, 145, 178, 255));"
        "   color: #ffffff;"
        "   padding: 12px 20px;"
        "   border: none;"
        "   border-right: 1px solid rgba(255, 255, 255, 0.15);"
        "   font-weight: 700;"
        "   font-size: 11pt;"
        "   letter-spacing: 1px;"
        "   text-transform: uppercase;"
        "}"
        "QHeaderView::section:last {"
        "   border: none;"
        "   border-right: none;"
        "   border-left: none;"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 rgba(16, 185, 129, 255), stop:0.5 rgba(5, 150, 105, 255), stop:1 rgba(4, 120, 87, 255));"
        "}"
    );

    QList tableRows = newTable->getRows();

    int rowCount = tableRows.size();
    int inputCount = tableRows[0].first.size();
    int colCount = inputCount + 1;


    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(colCount);

    // Headers
    QStringList headers;
    for (int i = 0; i < inputCount; ++i)
        headers << QString("In%1").arg(i + 1);
    headers << "Out";
    tableWidget->setHorizontalHeaderLabels(headers);

    // Fill with dark-themed styled cells
    for (int row = 0; row < rowCount; ++row) {
        const QVector<int>& inputs = tableRows[row].first;
        int output = tableRows[row].second;

        // Alternating row colors for better readability
        bool isEvenRow = (row % 2 == 0);

        for (int col = 0; col < inputCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(inputs[col]));
            item->setTextAlignment(Qt::AlignCenter);

            // Dark theme color scheme
            if (inputs[col] == 0) {
                if (isEvenRow) {
                    item->setBackground(QColor(127, 29, 29, 60));  // Dark red tint
                } else {
                    item->setBackground(QColor(127, 29, 29, 40));  // Darker red tint
                }
                item->setForeground(QColor("#f87171"));  // Bright red text
            } else {
                if (isEvenRow) {
                    item->setBackground(QColor(5, 150, 105, 60));  // Dark green tint
                } else {
                    item->setBackground(QColor(5, 150, 105, 40));  // Darker green tint
                }
                item->setForeground(QColor("#34d399"));  // Bright green text
            }

            item->setFont(QFont("Segoe UI", 15, QFont::Bold));
            tableWidget->setItem(row, col, item);
        }

        // Output column with emphasis
        QTableWidgetItem* outItem = new QTableWidgetItem(QString::number(output));
        outItem->setTextAlignment(Qt::AlignCenter);

        if (output == 0) {
            if (isEvenRow) {
                outItem->setBackground(QColor(185, 28, 28, 100));  // Red accent
            } else {
                outItem->setBackground(QColor(185, 28, 28, 70));  // Darker red accent
            }
            outItem->setForeground(QColor("#fca5a5"));  // Bright red text
        } else {
            if (isEvenRow) {
                outItem->setBackground(QColor(4, 120, 87, 100));  // Green accent
            } else {
                outItem->setBackground(QColor(4, 120, 87, 70));  // Darker green accent
            }
            outItem->setForeground(QColor("#6ee7b7"));  // Bright green text
        }

        outItem->setFont(QFont("Segoe UI", 16, QFont::ExtraBold));
        tableWidget->setItem(row, inputCount, outItem);
    }

    // Additional cleanup to remove any remaining borders
    tableWidget->horizontalHeader()->setStretchLastSection(false);

    ui->previewTableWidget->show();
    ui->truthTableTitle->show();
    ui->truthTableContainer->show();

    // Bring truth table elements to front
    ui->truthTableContainer->lower();
    ui->truthTableTitle->raise();
    ui->previewTableWidget->raise();

    // Resize table to fit contents and eliminate empty space
    tableWidget->resizeColumnsToContents();
    tableWidget->resizeRowsToContents();

    // Calculate the exact size needed for the table (no extra space)
    int tableWidth = 0;
    for (int i = 0; i < tableWidget->columnCount(); i++) {
        tableWidth += tableWidget->columnWidth(i);
    }

    int tableHeight = tableWidget->horizontalHeader()->height();
    for (int i = 0; i < tableWidget->rowCount(); i++) {
        tableHeight += tableWidget->rowHeight(i);
    }

    // Add minimal padding for frame
    tableWidth += 2;   // Just for the frame
    tableHeight += 2;  // Just for the frame

    // Resize the table widget to exact content size
    tableWidget->setFixedSize(tableWidth, tableHeight);
    tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Calculate horizontal center position based on central widget width
    int centralWidgetWidth = ui->centralwidget->width();
    int centeredX = (centralWidgetWidth / 2) - (tableWidth / 2);

    // Get title height
    int titleHeight = ui->truthTableTitle->height();
    int titleY = ui->truthTableTitle->y();
    int tableY = ui->previewTableWidget->y();

    // Adjust title width to match table and center it
    ui->truthTableTitle->setFixedWidth(tableWidth);
    ui->truthTableTitle->move(centeredX, titleY);

    // Position truth table centered horizontally
    tableWidget->move(centeredX, tableY);

    // Container perfectly encompasses title and table for shadow/border effect
    int containerHeight = (tableY - titleY) + tableHeight;  // From title start to table end
    ui->truthTableContainer->setGeometry(
        centeredX,
        titleY,
        tableWidth,
        containerHeight
    );

    ui->EvaluateButton->show();
    ui->EvaluateButton->setEnabled(true);
}

void MainWindow::getNextLevel(bool levelComplete, TruthTable *currentTable) {
    if (levelComplete){
        QMessageBox msgBox;
        msgBox.setWindowTitle("LEVEL COMPLETE!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("<div style='text-align: center;'>"
                       "<h1 style='color:#34d399; font-size:22pt; margin:10px;'>BRILLIANT!</h1>"
                       "<p style='color:#38bdf8; font-size:14pt; font-weight:bold;'>Perfect Circuit Design!</p>"
                       "</div>");
        msgBox.setInformativeText("<p style='font-size:11pt; color:#94a3b8;'>"
                                  "Your circuit correctly implements the required logic gate behavior.<br><br>"
                                  "<b style='color:#38bdf8;'>Ready for the next challenge?</b></p>");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 rgba(30, 41, 59, 250), stop:1 rgba(15, 23, 42, 255));"
            "   border: 1px solid rgba(52, 211, 153, 150);"
            "   border-radius: 12px;"
            "}"
            "QLabel {"
            "   color: #e2e8f0;"
            "   font-size: 11pt;"
            "   background: transparent;"
            "}"
            "QPushButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(16, 185, 129, 180), stop:1 rgba(5, 150, 105, 200));"
            "   color: white;"
            "   border: 1px solid rgba(52, 211, 153, 180);"
            "   border-radius: 8px;"
            "   padding: 10px 20px;"
            "   font-weight: bold;"
            "   font-size: 12pt;"
            "   min-width: 100px;"
            "}"
            "QPushButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(52, 211, 153, 200), stop:1 rgba(16, 185, 129, 220));"
            "   border: 1px solid rgba(110, 231, 183, 255);"
            "}"
        );
        msgBox.exec();
        //clean up input + output buttons
        for(DraggableButton* button: inputOutputButtons){
            button->hide();
            button->deleteLater();
        }
        inputOutputButtons.clear();

        currentLevel++;
        if(currentLevel >= 12){
            currentLevel = 100;
        }
        emit nextLevel(currentLevel);
    }
    else
    {
        // Display try again message.
        QMessageBox msgBox;
        msgBox.setWindowTitle("Needs Adjustment");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("<div style='text-align: center;'>"
                       "<h2 style='color:#fbbf24; font-size:16pt; margin:10px;'>Not Quite Right</h2>"
                       "<p style='color:#38bdf8; font-size:13pt; font-weight:bold;'>Circuit Output Mismatch</p>"
                       "</div>");
        msgBox.setInformativeText("<p style='font-size:10pt; color:#94a3b8;'>"
                                  "Your circuit doesn't produce the correct truth table.<br><br>"
                                  "<b style='color:#38bdf8;'>Hint:</b> <i>" + currentTable->getHint() + "</i><br><br>"
                                  "Check your gate connections and try again.</p>");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 rgba(30, 41, 59, 250), stop:1 rgba(15, 23, 42, 255));"
            "   border: 1px solid rgba(251, 191, 36, 150);"
            "   border-radius: 12px;"
            "}"
            "QLabel {"
            "   color: #e2e8f0;"
            "   font-size: 10pt;"
            "   background: transparent;"
            "}"
            "QPushButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(14, 165, 233, 180), stop:1 rgba(6, 182, 212, 200));"
            "   color: white;"
            "   border: 1px solid rgba(56, 189, 248, 180);"
            "   border-radius: 8px;"
            "   padding: 10px 20px;"
            "   font-weight: bold;"
            "   font-size: 12pt;"
            "   min-width: 100px;"
            "}"
            "QPushButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(56, 189, 248, 200), stop:1 rgba(34, 211, 238, 220));"
            "   border: 1px solid rgba(103, 232, 249, 255);"
            "}"
        );
        msgBox.exec();
        ui->EvaluateButton->setEnabled(true);

        return;
    }    
}

void MainWindow::evaluationAnimation(QMap<DraggableButton*, QVector<QPair<DraggableButton*, int>>> connections) {
    QVector<QPair<QPoint,QPoint>> wireSegments;

    // Collect all wire segments
    for (DraggableButton* sourceButton : connections.keys()) {
        // Map button position to backgroundGridLabel coordinates using global mapping
        // Output port at (44, 21), center at (48, 25) for 8x8 port
        QPoint sourceGlobal = sourceButton->mapToGlobal(QPoint(48, 25));
        QPoint startPos = backgroundGridLabel->mapFromGlobal(sourceGlobal);

        for (const auto& connection : connections.value(sourceButton)) {
            DraggableButton* targetButton = connection.first;
            int inputPort = connection.second;

            // Map target button position to backgroundGridLabel coordinates
            // For gates with 1 input (INVERTER, OUTPUT): input1 at (-2, 21), center = (2, 25 + 6)
            // For gates with 2 inputs: input1 at (-2, 9), input2 at (-2, 33)
            QPoint inputOffset;
            GateType targetGateType = targetButton->getGateType();

            if (targetGateType == GateType::INVERTER || targetGateType == GateType::OUTPUT) {
                // Single input gate - input is centered at (-2, 21), center at (2, 25)
                inputOffset = QPoint(2, 25);
            } else {
                // Two input gate
                switch (inputPort) {
                case 1: inputOffset = QPoint(2, 13); break;   // input1 top position center (9+4)
                case 2: inputOffset = QPoint(2, 37); break;   // input2 bottom position center (33+4)
                default: inputOffset = QPoint(2, 25); break;  // fallback center position
                }
            }
            QPoint targetGlobal = targetButton->mapToGlobal(inputOffset);
            QPoint endPos = backgroundGridLabel->mapFromGlobal(targetGlobal);

            if (startPos.x() > endPos.x()) {
                int verticalOffset = GATE_SIZE;
                if (startPos.y() + GATE_SIZE < endPos.y()) {
                    verticalOffset = -verticalOffset;
                }

                // Store backward wiring segments
                QPoint p1(startPos.x() + 20, startPos.y());
                wireSegments.push_back(QPair<QPoint,QPoint>(startPos, p1));

                QPoint p2(p1.x(), p1.y() - verticalOffset);
                wireSegments.push_back(QPair<QPoint,QPoint>(p1, p2));

                QPoint p3(endPos.x() - 20, endPos.y());
                QPoint p4(p3.x(), p3.y() - verticalOffset);
                wireSegments.push_back(QPair<QPoint,QPoint>(p4, p3));
                wireSegments.push_back(QPair<QPoint,QPoint>(p3, endPos));

                endPos = p4;
                startPos = p2;
            }

            // Store forward wiring segments
            int midX = (startPos.x() + endPos.x()) / 2;
            QPoint p1(midX, startPos.y());
            QPoint p2(midX, endPos.y());

            wireSegments.push_back(QPair<QPoint,QPoint>(startPos, p1));
            wireSegments.push_back(QPair<QPoint,QPoint>(p1, p2));
            wireSegments.push_back(QPair<QPoint,QPoint>(p2, endPos));
        }
    }

    std::sort(wireSegments.begin(), wireSegments.end(), []( QPair<QPoint, QPoint>& p1,  QPair<QPoint, QPoint>& p2) {
        return p1.first.x() < p2.first.x();
    });

    // Draw wire segments with delay
    QTimer* animationTimer = new QTimer(this);
    int* currentSegment = new int(0);

    connect(animationTimer, &QTimer::timeout, this, [this, wireSegments, currentSegment, animationTimer, connections]() {
        if (*currentSegment < wireSegments.size()) {
            drawWireArrow(wireSegments[*currentSegment].first, wireSegments[*currentSegment].second, true);

            backgroundGridLabel->setPixmap(*backgroundPixmap);

            (*currentSegment)++;
        } else {
            // Animation complete
            animationTimer->stop();
            delete currentSegment;
            animationTimer->deleteLater();

        }
    });
    animationTimer->start(400);
}

void MainWindow::displayLevelDescription(QString description) {
    QLabel *textLabel = ui->tipDescription;
    textLabel->setWordWrap(true);
    textLabel->setText(description);

    // Calculate optimal size based on content
    QFont font = textLabel->font();
    QFontMetrics fm(font);
    int maxWidth = 350;  // Max width for text content

    // Calculate text height with word wrapping
    QRect boundingRect = fm.boundingRect(0, 0, maxWidth, 1000,
                                         Qt::TextWordWrap | Qt::AlignCenter,
                                         description);

    // Set size with padding (10px top + 10px bottom + 15px left + 15px right + borders)
    int labelWidth = maxWidth + 36;  // 30px horizontal padding + 6px borders
    int labelHeight = boundingRect.height() + 26;  // 20px vertical padding + 6px borders

    textLabel->setFixedSize(labelWidth, labelHeight);

    // Center the level message horizontally based on central widget width
    int centralWidgetWidth = ui->centralwidget->width();
    int centeredX = (centralWidgetWidth / 2) - (labelWidth / 2);
    int yPos = 30;  // Fixed top position
    textLabel->move(centeredX, yPos);

    textLabel->show();
    ui->statusbar->showMessage("Tip: Read the level description above for hints", 3000);
}

void MainWindow::disableEvaluate() {
    ui->EvaluateButton->setEnabled(false);
}



void MainWindow::on_startButton_clicked()
{
    startLevel(1);
}

void MainWindow::returnToMenu(){
    // Clear workspace but keep UI visible

    // Reset to clean transparent background
    backgroundPixmap->fill(Qt::transparent);
    backgroundGridLabel->setPixmap(*backgroundPixmap);

    // Cleanup draggable gates
    for (auto button : draggableButtons) {
        button->buttonDelete();
    }
    QTimer::singleShot(100, this, [this]() {draggableButtons.clear();});

    // Show welcome screen
    ui->textEdit->show();
    ui->startButton->show();
    ui->gridLayoutWidget->show();

    // Re-center welcome screen elements
    centerWelcomeScreen();

    // Hide game elements
    ui->previewTableWidget->hide();
    ui->truthTableTitle->hide();
    ui->truthTableContainer->hide();
    ui->EvaluateButton->hide();
    ui->tipDescription->hide();
    ui->toolBar->hide();
    ui->menuButton->hide();

    // Cleanup input/output buttons
    for(DraggableButton* button : inputOutputButtons){
        button->hide();
    }
    inputOutputButtons.clear();

    disableToolBarActions();

    ui->statusbar->showMessage("Returned to menu", 2000);
}

void MainWindow::on_actionMENU_triggered()
{
    returnToMenu();
}


void MainWindow::gameOver() {
    disableToolBarActions();
    ui->EvaluateButton->setEnabled(false);
    QTextEdit *messageBox = new QTextEdit(this);
    messageBox->setReadOnly(true);
    messageBox->setGeometry(120, 120, 560, 400);
    messageBox->setStyleSheet(
        "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                             stop:0 rgba(15, 23, 42, 250),"
        "                             stop:0.5 rgba(30, 41, 59, 250),"
        "                             stop:1 rgba(15, 23, 42, 250));"
        "border: 2px solid rgba(52, 211, 153, 200);"
        "border-radius: 16px;"
        "padding: 20px;"
    );
    messageBox->setHtml(
        "<div align='center' style='padding: 20px;'>"
        "<h1 style='color:#34d399; font-size:36pt; margin-bottom:15px;'>VICTORY</h1>"
        "<p style='font-size:18pt; color:#38bdf8; margin:15px; font-weight:bold;'>ALL 12 LEVELS MASTERED</p>"
        "<p style='font-size:14pt; color:#94a3b8; margin:15px;'>Congratulations on completing every circuit challenge!</p>"
        "<p style='font-size:13pt; color:#e2e8f0; margin-top:20px;'>You are now a <b style='color:#38bdf8;'>Digital Logic Expert</b></p>"
        "<p style='font-size:11pt; color:#64748b; margin-top:25px;'>You've demonstrated mastery of:</p>"
        "<p style='font-size:11pt; color:#94a3b8;'>AND | OR | NOT | NAND | NOR | XOR | XNOR</p>"
        "<p style='font-size:11pt; color:#475569; margin-top:25px; font-style:italic;'>Return to menu to replay levels</p>"
        "</div>"
        );
    messageBox->show();
    messageBox->raise();
    ui->actionMENU->setEnabled(true);
    currentLevel =1;
    ui->statusbar->showMessage("All 12 levels completed! You are a Circuit Builder Master!", 15000);
}

void MainWindow::centerWelcomeScreen() {
    // Use central widget width instead of window width to account for toolbar
    int centralWidth = ui->centralwidget->width();

    // Only center if window has valid size
    if (centralWidth < 800) return;

    // Center the title text edit
    int textEditWidth = ui->textEdit->width();
    int textEditX = (centralWidth - textEditWidth) / 2;
    ui->textEdit->move(textEditX, ui->textEdit->y());

    // Center the start button
    int startButtonWidth = ui->startButton->width();
    int startButtonX = (centralWidth - startButtonWidth) / 2;
    ui->startButton->move(startButtonX, ui->startButton->y());

    // Center the levels grid
    int gridWidth = ui->gridLayoutWidget->width();
    int gridX = (centralWidth - gridWidth) / 2;
    ui->gridLayoutWidget->move(gridX, ui->gridLayoutWidget->y());
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    // Re-center welcome screen if it's visible
    if (ui->textEdit->isVisible() && ui->startButton->isVisible()) {
        centerWelcomeScreen();
    }
}


