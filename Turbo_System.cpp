#include <iostream>
#include <cmath>
#include <vector>

// Constants (can be tuned)
const double MAX_BOOST = 1.5; // Max boost pressure (in bar)
const double MIN_BOOST = 0.5; // Min boost pressure (in bar)
const double MAX_ENGINE_SPEED = 5000.0; // Max engine speed (RPM)
const double MAX_ENGINE_LOAD = 80.0; // Max engine load (percentage)
const double THROTTLE_SENSITIVITY = 1.5; // Sensitivity of throttle response
const double TURBO_EFFICIENCY = 0.80; // Efficiency of turbocharger

// Class for controlling the turbo boost
class TurboControlSystem {
public:
    // Method to calculate boost pressure based on engine speed and load
    double calculateBoost(double engineSpeed, double engineLoad) {
        // Ensure engine speed and load are within bounds
        engineSpeed = std::min(MAX_ENGINE_SPEED, std::max(0.0, engineSpeed));
        engineLoad = std::min(MAX_ENGINE_LOAD, std::max(0.0, engineLoad));

        // Basic boost formula: Higher engine speed and load = more boost
        double baseBoost = (engineSpeed / MAX_ENGINE_SPEED) * (engineLoad / MAX_ENGINE_LOAD) * MAX_BOOST;

        // Apply turbo efficiency and throttle sensitivity
        double effectiveBoost = baseBoost * TURBO_EFFICIENCY * THROTTLE_SENSITIVITY;

        // Limit boost to between the min and max values
        return std::min(MAX_BOOST, std::max(MIN_BOOST, effectiveBoost));
    }

    // Method to simulate the adjustment of the turbo Torque
    void adjustTorque(double boostPressure) {
        // Simulate adjusting the Torque to regulate boost pressure
        if (boostPressure > MAX_BOOST) {
            std::cout << "Torque is opening to reduce boost pressure." << std::endl;
        } else if (boostPressure < MIN_BOOST) {
            std::cout << "Torque is closing to increase boost pressure." << std::endl;
        } else {
            std::cout << "Boost pressure is optimal. Torque is maintaining position." << std::endl;
        }
    }

    // Method to simulate the engine performance under current boost
    void simulateEnginePerformance(double boostPressure) {
        // Calculate estimated power increase based on boost
        double powerIncrease = boostPressure * 100; // Simple model for power increase
        std::cout << "Turbo Boost Pressure: " << boostPressure << " bar" << std::endl;
        std::cout << "Estimated Power Increase: " << powerIncrease << " hp" << std::endl;
    }
};

// Main function to simulate turbo performance upgrade
int main() {
    TurboControlSystem turboSystem;

    double engineSpeed, engineLoad;
    std::cout << "Enter Engine Speed (RPM): ";
    std::cin >> engineSpeed;
    std::cout << "Enter Engine Load (%): ";
    std::cin >> engineLoad;

    // Calculate optimal boost based on inputs
    double boostPressure = turboSystem.calculateBoost(engineSpeed, engineLoad);

    // Adjust the Torque based on the boost pressure
    turboSystem.adjustTorque(boostPressure);

    // Simulate the engine performance under current boost pressure
    turboSystem.simulateEnginePerformance(boostPressure);

    return 0;
}






