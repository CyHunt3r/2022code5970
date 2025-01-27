#include <cmath>

#include <frc/smartdashboard/Smartdashboard.h>

#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

// Constructor, set following, direction, and set initial state to in and stopped
ShooterSubsystem::ShooterSubsystem() {

    ShooterMotor.Set(ControlMode::PercentOutput, 0.0);
}

// Methods

// Implementation of subsystem periodic method goes here.
// for example, publish encoder settings or motor currents to dashboard
void ShooterSubsystem::Periodic() {
// get the electric eye statuses

}

void ShooterSubsystem::Shoot() {
    ShooterMotor.Set(ControlMode::PercentOutput, kShootSpeed);
}

void ShooterSubsystem::ShootCheckRPM() {
// get RPMs from network tables to avoid a ShooterSubsystem dependancy
// Here we check that RPMS are within kRPM_OK on the low side.  Anything faster is ok
// If you're worried about goign to fast, change this calculation
    if ((frc::SmartDashboard::GetNumber("RPM",0.0) + SRPM_OK) >= STargetRPM) 
        ShooterMotor.Set(ControlMode::PercentOutput, kShootSpeed);
}

void ShooterSubsystem::Unjam() {
    ShooterMotor.Set(ControlMode::PercentOutput, -kShootSpeed);
}

void ShooterSubsystem::FeedForward() {
    ShooterMotor.Set(ControlMode::PercentOutput, kShootFeedForward);
}

void ShooterSubsystem::Stop() {
    ShooterMotor.Set(ControlMode::PercentOutput, 0.0);
}