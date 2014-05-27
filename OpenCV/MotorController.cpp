#include "MotorController.h"
#include"ImageProcessor.h"

MotorController::MotorController(void)
{
}


MotorController::~MotorController(void)
{
}

bool MotorController::connect(char *portName, DWORD baudRate)
{
    SP = new Serial(portName, baudRate);

    if (SP->IsConnected())
        printf("Robot connected.\n");

    return SP->IsConnected();
}

void MotorController::setUltraSonicSensor(char *portName, DWORD baudRate)
{
    MotorController::sensorPortName = portName;
    MotorController::sensorBaudRate = baudRate;
}

void MotorController::initializeUltraSonicSensor()
{
    MotorController::obstacleDetector.connect(MotorController::sensorPortName, MotorController::sensorBaudRate);
    MotorController::obstacleDetector.readState();

}

void MotorController::sendRawCommand (int command)
{
    int dataLength = 8;

    if(SP->IsConnected())
    {
        switch (command)
        {
        case MotorController::STOP:
            SP->WriteData("S",dataLength);
            printf("stop\n");
            break;
        case MotorController::MOVE_FORWARD:
            SP->WriteData("W",dataLength);
            printf("move forward\n");
            break;
        case MotorController::MOVE_BACKWARD:
            SP->WriteData("X",dataLength);
            printf("move backward\n");
            break;
        case MotorController::POINTTURN_LEFT:
            SP->WriteData("Z",dataLength);
            printf("point turn left\n");
            break;
        case MotorController::POINTTURN_RIGHT:
            SP->WriteData("C",dataLength);
            printf("point turn right\n");
            break;
        case MotorController::SWINGTURN_LEFT:
            SP->WriteData("A",dataLength);
            printf("swing turn left\n");
            break;
        case MotorController::SWINGTURN_RIGHT:
            SP->WriteData("D",dataLength);
            printf("swing turn right\n");
            break;
        case MotorController::CRUDETURN_LEFT:
            SP->WriteData("Q",dataLength);
            printf("crude turn left\n");
            break;
        case MotorController::CRUDETURN_RIGHT:
            SP->WriteData("E",dataLength);
            printf("crude turn right\n");
            break;
        case MotorController::NOTFOUND_PATROL:
            SP->WriteData("L",dataLength);
            printf("notfound\n");
            break;
        default:
            //SP->WriteData("S",dataLength);
            break;
        }
    }
}

void MotorController::sendCommandByVision (int visionCommand)
{
    switch (visionCommand)
    {
    case ImageProcessor::TENNISBALL_FRONT:
        sendRawCommand(MotorController::MOVE_FORWARD);
        break;
    case ImageProcessor::TENNISBALL_LEFT:
        sendRawCommand(MotorController::POINTTURN_LEFT);
        break;
    case ImageProcessor::TENNISBALL_RIGHT:
        sendRawCommand(MotorController::POINTTURN_RIGHT);
        break;
    case ImageProcessor::TENNISBALL_NOTFOUND:
        sendRawCommand(MotorController::NOTFOUND_PATROL);
        break;
    default:
        //SP->WriteData("S",dataLength);
        break;
    }
}