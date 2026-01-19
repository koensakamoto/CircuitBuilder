#ifndef DRAGGABLEBUTTON_H
#define DRAGGABLEBUTTON_H
#include <QPushButton>
#include <QMouseEvent>
#include <QIcon>
#include <QTimer>
#include <Box2D/Box2D.h>
#include "Gate.h"


class DraggableButton : public QPushButton
{
    Q_OBJECT

private:

    /**
     * @brief Used to represent the type of gate each button is.
     */
    GateType gateType;

    // Used for the input gates to distinguish on or off.
    QIcon const onIcon;
    QIcon const offIcon;

    QPoint dragStartPos;
    QPoint currentPos;

    /**
     * @brief wireModeOn Used to determine if buttons are being wired together. True when wiring.
     */
    bool wireModeOn = false;

    /**
     * @brief True when buttons or wires are being deleted.
     */
    bool isDelete = false;

    /**
     * @brief input1 Represents the first input of a logic gate.
     * Is disabled for input gates.
     */
    QPushButton input1;

    /**
     * @brief input2 Represents the second input of a logic gate.
     * Is disabled for inputs and inverters.
     */
    QPushButton input2;

    /**
     * @brief output Represents the output of a logic gate.
     * Is disabled for the output gate.
     */
    QPushButton output;

    // Needed for physics
    b2Body* body;
    int GRID_SIZE = 50;
    float PIXELS_PER_METER = 30.0f;

    QPoint snapToGrid(QPoint& point);
    void updatePhysicsBody(QPoint& newPos);

    /**
     * @brief Is the logical component represented by the DraggableButton class.
     */
    Gate* gate;

    // Input connection port - circular cyan dot (matches INPUT/OUTPUT gates)
    QString buttonStyle =
        "QPushButton {"
        "    background: #1e293b;"
        "    border: 1px solid #38bdf8;"
        "    border-radius: 4px;"
        "    min-width: 8px;"
        "    min-height: 8px;"
        "    max-width: 8px;"
        "    max-height: 8px;"
        "}"
        "QPushButton:hover {"
        "    background: #38bdf8;"
        "}"
        "QPushButton:pressed {"
        "    background: #0ea5e9;"
        "}";

    // Output connection port - circular green dot (matches INPUT/OUTPUT gates)
    QString outputButtonStyle =
        "QPushButton {"
        "    background: #1e293b;"
        "    border: 1px solid #34d399;"
        "    border-radius: 4px;"
        "    min-width: 8px;"
        "    min-height: 8px;"
        "    max-width: 8px;"
        "    max-height: 8px;"
        "}"
        "QPushButton:hover {"
        "    background: #34d399;"
        "}"
        "QPushButton:pressed {"
        "    background: #10b981;"
        "}";

    // Dark theme gate button styling - use DraggableButton selector to avoid affecting child port buttons
    QString mainButtonStyle =
        "DraggableButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                 stop:0 rgba(51, 65, 85, 200),"
        "                                 stop:1 rgba(30, 41, 59, 220));"
        "    border: 1px solid rgba(71, 85, 105, 150);"
        "    border-radius: 10px;"
        "    padding: 5px;"
        "}"
        "DraggableButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                 stop:0 rgba(56, 189, 248, 80),"
        "                                 stop:1 rgba(14, 165, 233, 100));"
        "    border: 1px solid rgba(56, 189, 248, 200);"
        "}"
        "DraggableButton:pressed {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "                                 stop:0 rgba(14, 165, 233, 150),"
        "                                 stop:1 rgba(2, 132, 199, 180));"
        "    border: 1px solid rgba(14, 165, 233, 200);"
        "}";


protected:
    /**
     * @brief Depending on program state, allows the button to wire, delete, or toggle signal.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Allows the button to be dragged around using the mouse.
     */
    void mouseMoveEvent(QMouseEvent *event) override;


public:

    // Base constuctor
    DraggableButton();

    /**
     * @brief Creates a button of gateType. Requires an actual gate as param.
     * Instantiates input buttons based on the gateType.
     */
    DraggableButton(GateType gateType, QWidget *parent = nullptr, Gate* gate = nullptr);

    /**
     * @brief buttonDelete Used to send the deletMe signal and run a delete animation for the button.
     */
    void buttonDelete();

    QPoint getPosition() { return currentPos; }

    /**
     * @brief Sets the top left corner of the button to the QPoint x,y position.
     */
    void setPosition(QPoint& pos);
    void setBody(b2Body* newBody) {body = newBody;}
    b2Body* getPhysicsBody();

    /**
     * @return The gate object the DraggableButton is representing.
     */
    Gate* getGate();

    /**
     * @return The gate type of this button.
     */
    GateType getGateType() const { return gateType; }

public slots:

    /**
     * @brief Recieves from MainWindow if the wire tool is active. True if wire tool is active.
     */
    void setWireMode(bool isWireOn);

    /**
     * @brief Recieves from MainWindow if the delete tool is active. True if the delete tool is active.
     */
    void setDeleteMode(bool isDelete);

    /**
     * @brief Sends input clicks to Circuit.
     */
    void input1Clicked();

    /**
     * @brief Sends input clicks to Circuit.
     */
    void input2Clicked();

    /**
     * @brief Sends output clicks to Circuit.
     */
    void outputClicked();

signals:

    /**
     * @brief sendButton
     * @param button
     * @param input 1 if input1, 2 if input2, 3 if output.
     * @param deletingWire True if the delete tool is active, false otherwise.
     */
    void sendButton(DraggableButton *button, int input, bool deletingWire);




    /**
     * @brief Sent to Circuit to indicate a button has been moved.
     */

    void onButtonMoved(DraggableButton* button);

    /**
     * @brief Sent to Circuit when the param button needs to be deleted.
     */
    void deleteMe(DraggableButton*);

    /**
     * @brief When an input gate is clicked, this tells Circuit to flip the input gates signal.
     */
    void toggleSignal(DraggableButton*);

};

#endif // DRAGGABLEBUTTON_H
