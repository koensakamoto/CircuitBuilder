#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <QPainter>
#include <QActionGroup>
#include <QPushButton>
#include "draggablebutton.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), circuit{Circuit(parent)}, draggableButtons{}
{
    ui->setupUi(this);

    // Apply clean and cohesive modern theme with blue accents
    this->setStyleSheet(
        "QMainWindow {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #f8fafc, stop:0.5 #e0f2fe, stop:1 #dbeafe);"
        "}"
        "QWidget#centralwidget {"
        "   background: transparent;"
        "}"
        "QToolBar {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 #ffffff, stop:1 #f0f9ff);"
        "   border: none;"
        "   border-right: 3px solid #00b4d8;"
        "   spacing: 12px;"
        "   padding: 15px 8px;"
        "}"
        "QToolBar::separator {"
        "   background: #00b4d8;"
        "   width: 2px;"
        "   margin: 8px 0px;"
        "}"
        "QToolBar QToolButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 #38bdf8, stop:1 #0ea5e9);"
        "   border: 2px solid #0ea5e9;"
        "   border-radius: 8px;"
        "   padding: 6px;"
        "   margin: 4px 2px;"
        "   min-width: 48px;"
        "   min-height: 48px;"
        "   max-width: 48px;"
        "   max-height: 48px;"
        "   color: white;"
        "   font-weight: bold;"
        "}"
        "QToolBar QToolButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 #7dd3fc, stop:1 #38bdf8);"
        "   border: 2px solid #38bdf8;"
        "   transform: scale(1.05);"
        "}"
        "QToolBar QToolButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 #0ea5e9, stop:1 #0284c7);"
        "   border: 2px solid #0284c7;"
        "}"
        "QToolBar QToolButton:checked {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "                                stop:0 #fbbf24, stop:1 #f59e0b);"
        "   border: 3px solid #fbbf24;"
        "   box-shadow: 0 0 20px #fbbf24;"
        "}"
        "QToolBar QToolButton:disabled {"
        "   background: #cbd5e1;"
        "   border: 2px solid #94a3b8;"
        "   color: #64748b;"
        "}"
        "QStatusBar {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "                                stop:0 #ffffff, stop:1 #f0f9ff);"
        "   color: #1e293b;"
        "   border-top: 2px solid #00b4d8;"
        "   padding: 8px;"
        "   font-size: 11pt;"
        "   font-weight: 500;"
        "}"
        "QTextEdit {"
        "   background: #ffffff;"
        "   border: 4px solid #00b4d8;"
        "   border-radius: 20px;"
        "   padding: 25px;"
        "   font-size: 14pt;"
        "   selection-background-color: #bae6fd;"
        "   color: #1e293b;"
        "}"
        "QPushButton {"
        "   font-size: 12pt;"
        "   font-weight: bold;"
        "   color: white;"
        "}"
        "QMenuBar {"
        "   background: #ffffff;"
        "   color: #1e293b;"
        "   border-bottom: 2px solid #00b4d8;"
        "   padding: 4px;"
        "}"
        "QMenuBar::item {"
        "   background: transparent;"
        "   padding: 6px 12px;"
        "   border-radius: 6px;"
        "}"
        "QMenuBar::item:selected {"
        "   background: #00b4d8;"
        "   color: white;"
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
            "                                stop:0 #f87171, stop:1 #ef4444);"
            "   border: 2px solid #ef4444;"
            "   border-radius: 8px;"
            "   padding: 8px;"
            "   margin: 4px 2px;"
            "   min-width: 48px;"
            "   min-height: 48px;"
            "   max-width: 48px;"
            "   max-height: 48px;"
            "   color: white;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #fca5a5, stop:1 #f87171);"
            "   border: 2px solid #fca5a5;"
            "}"
            "QToolButton:checked {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #ef4444, stop:1 #dc2626);"
            "   border: 3px solid #fbbf24;"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #dc2626, stop:1 #b91c1c);"
            "}"
        );
    }


    QWidget* wireWidget = ui->toolBar->widgetForAction(ui->actionWire);
    if (wireWidget) {
        wireWidget->setStyleSheet(
            "QToolButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #4ade80, stop:1 #22c55e);"
            "   border: 2px solid #22c55e;"
            "   border-radius: 8px;"
            "   padding: 8px;"
            "   margin: 4px 2px;"
            "   min-width: 48px;"
            "   min-height: 48px;"
            "   max-width: 48px;"
            "   max-height: 48px;"
            "   color: white;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #86efac, stop:1 #4ade80);"
            "   border: 2px solid #86efac;"
            "}"
            "QToolButton:checked {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #22c55e, stop:1 #16a34a);"
            "   border: 3px solid #fbbf24;"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #16a34a, stop:1 #15803d);"
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

    // Style the Menu button with cohesive amber/warning theme
    ui->menuButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #fbbf24, stop:1 #f59e0b);"
        "   border: 3px solid #f59e0b;"
        "   border-radius: 12px;"
        "   color: white;"
        "   font-size: 13pt;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #fcd34d, stop:1 #fbbf24);"
        "   border: 3px solid #fcd34d;"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #f59e0b, stop:1 #d97706);"
        "}"
    );

    // Set tooltip for the menu button
    ui->menuButton->setToolTip("Return to main menu");

    // Style Clear All button in toolbar with cohesive orange/amber theme
    QWidget* clearWidget = ui->toolBar->widgetForAction(ui->actionClear);
    if (clearWidget) {
        clearWidget->setStyleSheet(
            "QToolButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(251, 146, 60, 200),"
            "                                stop:1 rgba(249, 115, 22, 220));"
            "   border: 2px solid rgba(249, 115, 22, 200);"
            "   border-radius: 8px;"
            "   padding: 6px;"
            "   margin: 4px 2px;"
            "   min-width: 48px;"
            "   min-height: 48px;"
            "   max-width: 48px;"
            "   max-height: 48px;"
            "   color: white;"
            "   font-weight: bold;"
            "   font-size: 8pt;"
            "}"
            "QToolButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(253, 186, 116, 250),"
            "                                stop:1 rgba(251, 146, 60, 250));"
            "   border: 2px solid rgba(253, 186, 116, 255);"
            "}"
            "QToolButton:pressed {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 rgba(249, 115, 22, 255),"
            "                                stop:1 rgba(234, 88, 12, 255));"
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

    // Style the Start Button with cohesive blue theme
    ui->startButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #38bdf8, stop:1 #0ea5e9);"
        "   border: 5px solid #0ea5e9;"
        "   border-radius: 20px;"
        "   color: white;"
        "   font-size: 18pt;"
        "   font-weight: bold;"
        "   padding: 10px 20px;"
        "   text-transform: uppercase;"
        "   letter-spacing: 2px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #7dd3fc, stop:1 #38bdf8);"
        "   border: 5px solid #fbbf24;"
        "   transform: scale(1.05);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #0ea5e9, stop:1 #0284c7);"
        "   border: 5px solid #0284c7;"
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

    // Style the Evaluate Button with cohesive green success theme
    ui->EvaluateButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #34d399, stop:1 #10b981);"
        "   color: white;"
        "   border: 4px solid #10b981;"
        "   border-radius: 18px;"
        "   padding: 15px 30px;"
        "   font-size: 15pt;"
        "   font-weight: bold;"
        "   text-transform: uppercase;"
        "   letter-spacing: 1px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #6ee7b7, stop:1 #34d399);"
        "   border: 4px solid #fbbf24;"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #10b981, stop:1 #059669);"
        "   border: 4px solid #059669;"
        "}"
        "QPushButton:disabled {"
        "   background: #cbd5e1;"
        "   border: 3px solid #94a3b8;"
        "   color: #64748b;"
        "}"
    );
    ui->EvaluateButton->setToolTip("Check if your circuit produces the correct truth table");

    // Style the tip description label with cohesive blue theme
    ui->tipDescription->setStyleSheet(
        "QLabel {"
        "   background: #f0f9ff;"
        "   border: 3px solid #00b4d8;"
        "   border-radius: 10px;"
        "   padding: 10px 15px;"
        "   font-size: 10pt;"
        "   font-weight: 600;"
        "   color: #1e293b;"
        "   line-height: 1.4;"
        "}"
    );

    // Style the truth table title with premium gradient and shadow
    ui->truthTableTitle->setStyleSheet(
        "QLabel {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #0ea5e9, stop:0.5 #0284c7, stop:1 #0369a1);"
        "   color: #ffffff;"
        "   font-size: 14pt;"
        "   font-weight: 700;"
        "   letter-spacing: 2.5px;"
        "   border-top-left-radius: 12px;"
        "   border-top-right-radius: 12px;"
        "   padding: 12px;"
        "   text-shadow: 0px 2px 4px rgba(0, 0, 0, 0.25);"
        "}"
    );

    // Style the truth table container with modern shadow effect
    ui->truthTableContainer->setStyleSheet(
        "QWidget {"
        "   background: #ffffff;"
        "   border-radius: 12px;"
        "   border: none;"
        "   box-shadow: 0px 4px 12px rgba(0, 0, 0, 0.1);"
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
    ui->statusbar->showMessage("Workspace cleared! All gates removed.", 3000);
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
        QPoint startPos = sourceButton->pos() - QPoint(GATE_SIZE/2, -GATE_SIZE/2);

        // Loop over each connection for source button
        for (const auto& connection : connections.value(sourceButton)) {
            DraggableButton* targetButton = connection.first;
            int inputPort = connection.second;

            // Calculate end position with input port offset
            QPoint endPos = targetButton->pos() - QPoint(GATE_SIZE/2, -GATE_SIZE/2);
            QPoint offset;
            switch (inputPort) {
            case 1: offset = QPoint(-10, -12); break;
            case 2: offset = QPoint(-10, 12); break;
            default: offset = QPoint(0, 0); break;
            }
            endPos += offset;

            // Handle backward wiring (when start is to the right of end)
            if (startPos.x() > endPos.x()) {
                int verticalOffset = GATE_SIZE;
                // See if it closer to go up or down
                if (startPos.y() + GATE_SIZE < endPos.y()) {
                    verticalOffset = -verticalOffset;
                }

                // Draw first segment
                QPoint p1(startPos.x() + GATE_SIZE, startPos.y());
                drawWireArrow(startPos, p1, false);

                // Draw second segment (vertical)
                QPoint p2(p1.x(), p1.y() - verticalOffset);
                drawWireArrow(p1, p2, false);

                // Draw third and fourth segments
                QPoint p3(endPos.x() - GATE_SIZE, endPos.y());
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
    int arrowSize = 10;

    QPainter painter(backgroundPixmap);

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
    if(animating){
        painter.setPen(QPen(Qt::blue, 4, Qt::SolidLine, Qt::RoundCap));
    }

    painter.drawLine(start,end);

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

    painter.setBrush(QBrush(Qt::blue));
    painter.drawPolygon(triangle);
}


void MainWindow::onWireClicked(bool checked) {
    if (checked) {
        disableToolBarActions();
        ui->actionWire->setEnabled(true);
        ui->statusbar->showMessage("WIRE MODE ACTIVE - Click gates to connect them together", 0);
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
        ui->statusbar->showMessage("DELETE MODE ACTIVE - Click gates to remove them", 0);
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

    ui->startButton->hide();
    ui->gridLayoutWidget->hide();

    ui->textEdit->hide();

    ui->statusbar->showMessage(QString("LEVEL %1 STARTED - Build your circuit using the toolbar!").arg(currentLevel + 1), 5000);

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

        // Style input gates with cohesive blue theme
        input->setStyleSheet(
            "DraggableButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 #38bdf8, stop:1 #0ea5e9);"
            "   border: 3px solid #0ea5e9;"
            "   border-radius: 6px;"
            "}"
            "DraggableButton:hover {"
            "   border: 3px solid #fbbf24;"
            "}"
        );

        inputOutputButtons.push_back(input);
    }

    // Create output gate with enhanced styling - centered vertically on screen
    p = QPoint(850, outputY);
    DraggableButton* output = createGateButton(GateType::OUTPUT, ui->actionInputGate->icon());
    output->move(p);

    // Style output gate with cohesive green success theme
    output->setStyleSheet(
        "DraggableButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #34d399, stop:1 #10b981);"
        "   border: 3px solid #10b981;"
        "   border-radius: 6px;"
        "}"
        "DraggableButton:hover {"
        "   border: 3px solid #fbbf24;"
        "}"
    );

    inputOutputButtons.push_back(output);
    // Pull data out of truthtable
    QTableWidget* tableWidget = ui->previewTableWidget;
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->verticalHeader()->setVisible(false);  // Hide row numbers
    tableWidget->setShowGrid(true);
    tableWidget->setFrameShape(QFrame::NoFrame);  // Remove frame border
    tableWidget->setCornerButtonEnabled(false);  // Disable corner button
    tableWidget->horizontalHeader()->setHighlightSections(false);  // No highlight

    // Premium, polished truth table design with modern aesthetics
    tableWidget->setStyleSheet(
        "QTableWidget {"
        "   background: #ffffff;"
        "   border: 0px;"
        "   border-radius: 0px 0px 12px 12px;"
        "   gridline-color: #e2e8f0;"
        "   font-size: 15pt;"
        "   font-weight: 600;"
        "   selection-background-color: transparent;"
        "   font-family: 'Segoe UI', 'SF Pro Display', Arial, sans-serif;"
        "   outline: none;"
        "}"
        "QTableWidget::item {"
        "   padding: 18px 24px;"
        "   border: none;"
        "   border-bottom: 1px solid #f1f5f9;"
        "   border-right: 1px solid #e2e8f0;"
        "   color: #0f172a;"
        "}"
        "QTableWidget::item:selected {"
        "   background: transparent;"
        "}"
        "QHeaderView {"
        "   border: none;"
        "   outline: none;"
        "}"
        "QHeaderView::section {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #0ea5e9, stop:0.5 #0284c7, stop:1 #0369a1);"
        "   color: #ffffff;"
        "   padding: 16px 24px;"
        "   border: none;"
        "   border-right: 1px solid rgba(255, 255, 255, 0.2);"
        "   font-weight: 700;"
        "   font-size: 12pt;"
        "   letter-spacing: 1.2px;"
        "   text-transform: uppercase;"
        "   text-shadow: 0px 1px 2px rgba(0, 0, 0, 0.2);"
        "}"
        "QHeaderView::section:last {"
        "   border: none;"
        "   border-right: none;"
        "   border-left: none;"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                stop:0 #10b981, stop:0.5 #059669, stop:1 #047857);"
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

    // Fill with beautifully styled cells
    for (int row = 0; row < rowCount; ++row) {
        const QVector<int>& inputs = tableRows[row].first;
        int output = tableRows[row].second;

        // Alternating row colors for better readability
        bool isEvenRow = (row % 2 == 0);

        for (int col = 0; col < inputCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(inputs[col]));
            item->setTextAlignment(Qt::AlignCenter);

            // Premium polished color scheme with subtle gradients
            if (inputs[col] == 0) {
                if (isEvenRow) {
                    item->setBackground(QColor("#fef2f2"));  // Ultra light red
                } else {
                    item->setBackground(QColor("#fee2e2"));  // Very light red
                }
                item->setForeground(QColor("#dc2626"));  // Rich red text
            } else {
                if (isEvenRow) {
                    item->setBackground(QColor("#f0fdf4"));  // Ultra light green
                } else {
                    item->setBackground(QColor("#dcfce7"));  // Very light green
                }
                item->setForeground(QColor("#059669"));  // Rich green text
            }

            item->setFont(QFont("Segoe UI", 17, QFont::Bold));
            tableWidget->setItem(row, col, item);
        }

        // Output column with premium emphasis and stronger visual hierarchy
        QTableWidgetItem* outItem = new QTableWidgetItem(QString::number(output));
        outItem->setTextAlignment(Qt::AlignCenter);

        if (output == 0) {
            if (isEvenRow) {
                outItem->setBackground(QColor("#fecaca"));  // Soft red
            } else {
                outItem->setBackground(QColor("#fca5a5"));  // Medium red
            }
            outItem->setForeground(QColor("#b91c1c"));  // Deep red text
        } else {
            if (isEvenRow) {
                outItem->setBackground(QColor("#86efac"));  // Soft green
            } else {
                outItem->setBackground(QColor("#6ee7b7"));  // Medium green
            }
            outItem->setForeground(QColor("#047857"));  // Deep green text
        }

        outItem->setFont(QFont("Segoe UI", 18, QFont::ExtraBold));
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
                       "<h1 style='color:#10b981; font-size:24pt; margin:10px;'>BRILLIANT!</h1>"
                       "<p style='color:#00b4d8; font-size:16pt; font-weight:bold;'>Perfect Circuit Design!</p>"
                       "</div>");
        msgBox.setInformativeText("<p style='font-size:12pt; color:#2d3748;'>"
                                  "Your circuit correctly implements the required logic gate behavior.<br><br>"
                                  "<b style='color:#00b4d8;'>Ready for the next challenge?</b></p>");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 #f0f9ff, stop:1 #e0f2fe);"
            "   border: 4px solid #00b4d8;"
            "   border-radius: 15px;"
            "}"
            "QLabel {"
            "   color: #2d3748;"
            "   font-size: 12pt;"
            "   background: transparent;"
            "}"
            "QPushButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #10b981, stop:1 #059669);"
            "   color: white;"
            "   border: 3px solid #10b981;"
            "   border-radius: 10px;"
            "   padding: 12px 24px;"
            "   font-weight: bold;"
            "   font-size: 13pt;"
            "   min-width: 120px;"
            "}"
            "QPushButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #34d399, stop:1 #10b981);"
            "   border: 3px solid #ffc107;"
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
        msgBox.setWindowTitle("🔧 NEEDS ADJUSTMENT");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("<div style='text-align: center;'>"
                       "<h2 style='color:#f59e0b; font-size:18pt; margin:10px;'>⚠️ Not Quite There!</h2>"
                       "<p style='color:#00b4d8; font-size:14pt; font-weight:bold;'>Circuit Output Doesn't Match</p>"
                       "</div>");
        msgBox.setInformativeText("<p style='font-size:11pt; color:#2d3748;'>"
                                  "Your circuit doesn't produce the correct truth table.<br><br>"
                                  "<b style='color:#00b4d8;'>Hint:</b> <i>" + currentTable->getHint() + "</i><br><br>"
                                  "Double-check your gate connections and try again!</p>");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QMessageBox {"
            "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
            "                                stop:0 #fffbeb, stop:1 #fef3c7);"
            "   border: 4px solid #f59e0b;"
            "   border-radius: 15px;"
            "}"
            "QLabel {"
            "   color: #2d3748;"
            "   font-size: 11pt;"
            "   background: transparent;"
            "}"
            "QPushButton {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #00b4d8, stop:1 #0096c7);"
            "   color: white;"
            "   border: 3px solid #00b4d8;"
            "   border-radius: 10px;"
            "   padding: 12px 24px;"
            "   font-weight: bold;"
            "   font-size: 13pt;"
            "   min-width: 120px;"
            "}"
            "QPushButton:hover {"
            "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
            "                                stop:0 #48cae4, stop:1 #00b4d8);"
            "   border: 3px solid #ffc107;"
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
        QPoint startPos = sourceButton->pos() - QPoint(GATE_SIZE/2, -GATE_SIZE/2);

        for (const auto& connection : connections.value(sourceButton)) {
            DraggableButton* targetButton = connection.first;
            int inputPort = connection.second;

            QPoint endPos = targetButton->pos() - QPoint(GATE_SIZE/2, -GATE_SIZE/2);
            QPoint offset;
            switch (inputPort) {
            case 1: offset = QPoint(-10, -12); break;
            case 2: offset = QPoint(-10, 12); break;
            default: offset = QPoint(0, 0); break;
            }
            endPos += offset;

            if (startPos.x() > endPos.x()) {
                int verticalOffset = GATE_SIZE;
                if (startPos.y() + GATE_SIZE < endPos.y()) {
                    verticalOffset = -verticalOffset;
                }

                // Store backward wiring segments
                QPoint p1(startPos.x() + GATE_SIZE, startPos.y());
                wireSegments.push_back(QPair<QPoint,QPoint>(startPos, p1));

                QPoint p2(p1.x(), p1.y() - verticalOffset);
                wireSegments.push_back(QPair<QPoint,QPoint>(p1, p2));

                QPoint p3(endPos.x() - GATE_SIZE, endPos.y());
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
    ui->statusbar->showMessage("Read the level description for helpful tips!", 3000);
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
        "                             stop:0 rgba(0, 200, 255, 250),"
        "                             stop:0.5 rgba(0, 180, 216, 250),"
        "                             stop:1 rgba(0, 150, 199, 250));"
        "border: 6px solid rgba(255, 193, 7, 230);"
        "border-radius: 25px;"
        "padding: 25px;"
    );
    messageBox->setHtml(
        "<div align='center' style='padding: 25px;'>"
        "<h1 style='color:#FFD700; font-size:42pt; margin-bottom:15px; text-shadow: 3px 3px 6px rgba(0,0,0,0.3);'>VICTORY!</h1>"
        "<p style='font-size:22pt; color:#FFFFFF; margin:15px; font-weight:bold; text-shadow: 2px 2px 4px rgba(0,0,0,0.3);'>ALL 12 LEVELS MASTERED!</p>"
        "<p style='font-size:16pt; color:#F0F9FF; margin:15px;'>Congratulations on completing every circuit challenge!</p>"
        "<p style='font-size:14pt; color:#E0F2FE; margin-top:25px;'>You are now a <b>Digital Logic Expert</b>!</p>"
        "<p style='font-size:12pt; color:#DBEAFE; margin-top:30px;'>You've demonstrated mastery of:</p>"
        "<p style='font-size:11pt; color:#DBEAFE;'>AND • OR • NOT • NAND • NOR • XOR • XNOR Gates</p>"
        "<p style='font-size:11pt; color:#BAE6FD; margin-top:30px; font-style:italic;'>Close the application or return to menu to replay levels</p>"
        "</div>"
        );
    messageBox->show();
    messageBox->raise();
    ui->actionMENU->setEnabled(true);
    currentLevel =1;
    ui->statusbar->showMessage("🎊 PERFECT! All 12 levels completed! You are a Circuit Builder MASTER! 🎊", 15000);
}


