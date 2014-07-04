#!/bin/sh



xcrun xcodebuild -project Chapter01_Vectors/Ex11_BallWithoutVectors/xcode/Ex11_BallWithoutVectors.xcodeproj -target Ex11_BallWithoutVectors -configuration Release $@
mv Chapter01_Vectors/Ex11_BallWithoutVectors/xcode/build/Release/Ex11_BallWithoutVectors.app ./build/Ex11_BallWithoutVectors.app
rm -r Chapter01_Vectors/Ex11_BallWithoutVectors/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex12_BallWithVectors/xcode/Ex12_BallWithVectors.xcodeproj -target Ex12_BallWithVectors -configuration Release $@
mv Chapter01_Vectors/Ex12_BallWithVectors/xcode/build/Release/Ex12_BallWithVectors.app ./build/Ex12_BallWithVectors.app
rm -r Chapter01_Vectors/Ex12_BallWithVectors/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex13_VectorSandbox/xcode/Ex13_VectorSandbox.xcodeproj -target Ex13_VectorSandbox -configuration Release $@
mv Chapter01_Vectors/Ex13_VectorSandbox/xcode/build/Release/Ex13_VectorSandbox.app ./build/Ex13_VectorSandbox.app
rm -r Chapter01_Vectors/Ex13_VectorSandbox/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex14_VectorAccelConst/xcode/Ex14_VectorAccelConst.xcodeproj -target Ex14_VectorAccelConst -configuration Release $@
mv Chapter01_Vectors/Ex14_VectorAccelConst/xcode/build/Release/Ex14_VectorAccelConst.app ./build/Ex14_VectorAccelConst.app
rm -r Chapter01_Vectors/Ex14_VectorAccelConst/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex15_VectorAccelRandom/xcode/Ex15_VectorAccelRandom.xcodeproj -target Ex15_VectorAccelRandom -configuration Release $@
mv Chapter01_Vectors/Ex15_VectorAccelRandom/xcode/build/Release/Ex15_VectorAccelRandom.app ./build/Ex15_VectorAccelRandom.app
rm -r Chapter01_Vectors/Ex15_VectorAccelRandom/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex16_VectorAccelMouse/xcode/Ex16_VectorAccelMouse.xcodeproj -target Ex16_VectorAccelMouse -configuration Release $@
mv Chapter01_Vectors/Ex16_VectorAccelMouse/xcode/build/Release/Ex16_VectorAccelMouse.app ./build/Ex16_VectorAccelMouse.app
rm -r Chapter01_Vectors/Ex16_VectorAccelMouse/xcode/build*

xcrun xcodebuild -project Chapter01_Vectors/Ex17_StupidFlock/xcode/Ex17_StupidFlock.xcodeproj -target Ex17_StupidFlock -configuration Release $@
mv Chapter01_Vectors/Ex17_StupidFlock/xcode/build/Release/Ex17_StupidFlock.app ./build/Ex17_StupidFlock.app
rm -r Chapter01_Vectors/Ex17_StupidFlock/xcode/build*



xcrun xcodebuild -project Chapter02_Forces/Ex21Wind/xcode/Ex21Wind.xcodeproj -target Ex21Wind -configuration Release $@
mv Chapter02_Forces/Ex21Wind/xcode/build/Release/Ex21Wind.app ./build/Ex21Wind.app
rm -r Chapter02_Forces/Ex21Wind/xcode/build*

xcrun xcodebuild -project Chapter02_Forces/Ex22Gravity/xcode/Ex22Gravity.xcodeproj -target Ex22Gravity -configuration Release $@
mv Chapter02_Forces/Ex22Gravity/xcode/build/Release/Ex22Gravity.app ./build/Ex22Gravity.app
rm -r Chapter02_Forces/Ex22Gravity/xcode/build*

xcrun xcodebuild -project Chapter02_Forces/Ex23Friction/xcode/Ex23Friction.xcodeproj -target Ex23Friction -configuration Release $@
mv Chapter02_Forces/Ex23Friction/xcode/build/Release/Ex23Friction.app ./build/Ex23Friction.app
rm -r Chapter02_Forces/Ex23Friction/xcode/build*

xcrun xcodebuild -project Chapter02_Forces/Ex24FluidResistance/xcode/Ex24FluidResistance.xcodeproj -target Ex24FluidResistance -configuration Release $@
mv Chapter02_Forces/Ex24FluidResistance/xcode/build/Release/Ex24FluidResistance.app ./build/Ex24FluidResistance.app
rm -r Chapter02_Forces/Ex24FluidResistance/xcode/build*

xcrun xcodebuild -project Chapter02_Forces/Ex25GravitationalAttractors/xcode/Ex25GravitationalAttractors.xcodeproj -target Ex25GravitationalAttractors -configuration Release $@
mv Chapter02_Forces/Ex25GravitationalAttractors/xcode/build/Release/Ex25GravitationalAttractors.app ./build/Ex25GravitationalAttractors.app
rm -r Chapter02_Forces/Ex25GravitationalAttractors/xcode/build*

xcrun xcodebuild -project Chapter02_Forces/Ex26EverythingAttracts/xcode/Ex26EverythingAttracts.xcodeproj -target Ex26EverythingAttracts -configuration Release $@
mv Chapter02_Forces/Ex26EverythingAttracts/xcode/build/Release/Ex26EverythingAttracts.app ./build/Ex26EverythingAttracts.app
rm -r Chapter02_Forces/Ex26EverythingAttracts/xcode/build*



xcrun xcodebuild -project Chapter03_Oscillation/Ex31SpinningBasics/xcode/Ex31SpinningBasics.xcodeproj -target Ex31SpinningBasics -configuration Release $@
mv Chapter03_Oscillation/Ex31SpinningBasics/xcode/build/Release/Ex31SpinningBasics.app ./build/Ex31SpinningBasics.app
rm -r Chapter03_Oscillation/Ex31SpinningBasics/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex32DirectionOfMovement/xcode/Ex32DirectionOfMovement.xcodeproj -target Ex32DirectionOfMovement -configuration Release $@
mv Chapter03_Oscillation/Ex32DirectionOfMovement/xcode/build/Release/Ex32DirectionOfMovement.app ./build/Ex32DirectionOfMovement.app
rm -r Chapter03_Oscillation/Ex32DirectionOfMovement/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex33Asteroids/xcode/Ex33Asteroids.xcodeproj -target Ex33Asteroids -configuration Release $@
mv Chapter03_Oscillation/Ex33Asteroids/xcode/build/Release/Ex33Asteroids.app ./build/Ex33Asteroids.app
rm -r Chapter03_Oscillation/Ex33Asteroids/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex34SimpleHarmonicMotion/xcode/Ex34SimpleHarmonicMotion.xcodeproj -target Ex34SimpleHarmonicMotion -configuration Release $@
mv Chapter03_Oscillation/Ex34SimpleHarmonicMotion/xcode/build/Release/Ex34SimpleHarmonicMotion.app ./build/Ex34SimpleHarmonicMotion.app
rm -r Chapter03_Oscillation/Ex34SimpleHarmonicMotion/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex35Waves/xcode/Ex35Waves.xcodeproj -target Ex35Waves -configuration Release $@
mv Chapter03_Oscillation/Ex35Waves/xcode/build/Release/Ex35Waves.app ./build/Ex35Waves.app
rm -r Chapter03_Oscillation/Ex35Waves/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex36Pendulum/xcode/Ex36Pendulum.xcodeproj -target Ex36Pendulum -configuration Release $@
mv Chapter03_Oscillation/Ex36Pendulum/xcode/build/Release/Ex36Pendulum.app ./build/Ex36Pendulum.app
rm -r Chapter03_Oscillation/Ex36Pendulum/xcode/build*

xcrun xcodebuild -project Chapter03_Oscillation/Ex37Spring/xcode/Ex37Spring.xcodeproj -target Ex37Spring -configuration Release $@
mv Chapter03_Oscillation/Ex37Spring/xcode/build/Release/Ex37Spring.app ./build/Ex37Spring.app
rm -r Chapter03_Oscillation/Ex37Spring/xcode/build*



xcrun xcodebuild -project Chapter04_ParticleSystems/Ex41SingleParticle/xcode/Ex41SingleParticle.xcodeproj -target Ex41SingleParticle -configuration Release $@
mv Chapter04_ParticleSystems/Ex41SingleParticle/xcode/build/Release/Ex41SingleParticle.app ./build/Ex41SingleParticle.app
rm -r Chapter04_ParticleSystems/Ex41SingleParticle/xcode/build*

xcrun xcodebuild -project Chapter04_ParticleSystems/Ex42ParticleVector/xcode/Ex42ParticleVector.xcodeproj -target Ex42ParticleVector -configuration Release $@
mv Chapter04_ParticleSystems/Ex42ParticleVector/xcode/build/Release/Ex42ParticleVector.app ./build/Ex42ParticleVector.app
rm -r Chapter04_ParticleSystems/Ex42ParticleVector/xcode/build*

xcrun xcodebuild -project Chapter04_ParticleSystems/Ex43ParticleSystems/xcode/Ex43ParticleSystems.xcodeproj -target Ex43ParticleSystems -configuration Release $@
mv Chapter04_ParticleSystems/Ex43ParticleSystems/xcode/build/Release/Ex43ParticleSystems.app ./build/Ex43ParticleSystems.app
rm -r Chapter04_ParticleSystems/Ex43ParticleSystems/xcode/build*

xcrun xcodebuild -project Chapter04_ParticleSystems/Ex44ParticlePolymorphism/xcode/Ex44ParticlePolymorphism.xcodeproj -target Ex44ParticlePolymorphism -configuration Release $@
mv Chapter04_ParticleSystems/Ex44ParticlePolymorphism/xcode/build/Release/Ex44ParticlePolymorphism.app ./build/Ex44ParticlePolymorphism.app
rm -r Chapter04_ParticleSystems/Ex44ParticlePolymorphism/xcode/build*

xcrun xcodebuild -project Chapter04_ParticleSystems/Ex45ParticleRepeller/xcode/Ex45ParticleRepeller.xcodeproj -target Ex45ParticleRepeller -configuration Release $@
mv Chapter04_ParticleSystems/Ex45ParticleRepeller/xcode/build/Release/Ex45ParticleRepeller.app ./build/Ex45ParticleRepeller.app
rm -r Chapter04_ParticleSystems/Ex45ParticleRepeller/xcode/build*

xcrun xcodebuild -project Chapter04_ParticleSystems/Ex46TexturedParticles/xcode/Ex46TexturedParticles.xcodeproj -target Ex46TexturedParticles -configuration Release $@
mv Chapter04_ParticleSystems/Ex46TexturedParticles/xcode/build/Release/Ex46TexturedParticles.app ./build/Ex46TexturedParticles.app
rm -r Chapter04_ParticleSystems/Ex46TexturedParticles/xcode/build*



xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex51aBox2DCustom/xcode/Ex51aBox2DCustom.xcodeproj -target Ex51aBox2DCustom -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex51aBox2DCustom/xcode/build/Release/Ex51aBox2DCustom.app ./build/Ex51aBox2DCustom.app
rm -r Chapter05_PhysicsLibraries/Ex51aBox2DCustom/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex52FixedObjects/xcode/Ex52FixedObjects.xcodeproj -target Ex52FixedObjects -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex52FixedObjects/xcode/build/Release/Ex52FixedObjects.app ./build/Ex52FixedObjects.app
rm -r Chapter05_PhysicsLibraries/Ex52FixedObjects/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex53CurvyBoundaries/xcode/Ex53CurvyBoundaries.xcodeproj -target Ex53CurvyBoundaries -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex53CurvyBoundaries/xcode/build/Release/Ex53CurvyBoundaries.app ./build/Ex53CurvyBoundaries.app
rm -r Chapter05_PhysicsLibraries/Ex53CurvyBoundaries/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex54ComplexForms/xcode/Ex54ComplexForms.xcodeproj -target Ex54ComplexForms -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex54ComplexForms/xcode/build/Release/Ex54ComplexForms.app ./build/Ex54ComplexForms.app
rm -r Chapter05_PhysicsLibraries/Ex54ComplexForms/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex55Joints/xcode/Ex55Joints.xcodeproj -target Ex55Joints -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex55Joints/xcode/build/Release/Ex55Joints.app ./build/Ex55Joints.app
rm -r Chapter05_PhysicsLibraries/Ex55Joints/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex56Forces/xcode/Ex56Forces.xcodeproj -target Ex56Forces -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex56Forces/xcode/build/Release/Ex56Forces.app ./build/Ex56Forces.app
rm -r Chapter05_PhysicsLibraries/Ex56Forces/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex57Collisions/xcode/Ex57Collisions.xcodeproj -target Ex57Collisions -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex57Collisions/xcode/build/Release/Ex57Collisions.app ./build/Ex57Collisions.app
rm -r Chapter05_PhysicsLibraries/Ex57Collisions/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex58AdvancedCollisions/xcode/Ex58AdvancedCollisions.xcodeproj -target Ex58AdvancedCollisions -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex58AdvancedCollisions/xcode/build/Release/Ex58AdvancedCollisions.app ./build/Ex58AdvancedCollisions.app
rm -r Chapter05_PhysicsLibraries/Ex58AdvancedCollisions/xcode/build*

xcrun xcodebuild -project Chapter05_PhysicsLibraries/Ex59AdvancedJoints/xcode/Ex59AdvancedJoints.xcodeproj -target Ex59AdvancedJoints -configuration Release $@
mv Chapter05_PhysicsLibraries/Ex59AdvancedJoints/xcode/build/Release/Ex59AdvancedJoints.app ./build/Ex59AdvancedJoints.app
rm -r Chapter05_PhysicsLibraries/Ex59AdvancedJoints/xcode/build*



xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex61SelfSteeringVehicle/xcode/Ex61SelfSteeringVehicle.xcodeproj -target Ex61SelfSteeringVehicle -configuration Release $@
mv Chapter06_AutonomousAgents/Ex61SelfSteeringVehicle/xcode/build/Release/Ex61SelfSteeringVehicle.app ./build/Ex61SelfSteeringVehicle.app
rm -r Chapter06_AutonomousAgents/Ex61SelfSteeringVehicle/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex62WanderingVehicle/xcode/Ex62WanderingVehicle.xcodeproj -target Ex62WanderingVehicle -configuration Release $@
mv Chapter06_AutonomousAgents/Ex62WanderingVehicle/xcode/build/Release/Ex62WanderingVehicle.app ./build/Ex62WanderingVehicle.app
rm -r Chapter06_AutonomousAgents/Ex62WanderingVehicle/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex63StayingWithinWalls/xcode/Ex63StayingWithinWalls.xcodeproj -target Ex63StayingWithinWalls -configuration Release $@
mv Chapter06_AutonomousAgents/Ex63StayingWithinWalls/xcode/build/Release/Ex63StayingWithinWalls.app ./build/Ex63StayingWithinWalls.app
rm -r Chapter06_AutonomousAgents/Ex63StayingWithinWalls/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex64FlowFieldFollowing/xcode/Ex64FlowFieldFollowing.xcodeproj -target Ex64FlowFieldFollowing -configuration Release $@
mv Chapter06_AutonomousAgents/Ex64FlowFieldFollowing/xcode/build/Release/Ex64FlowFieldFollowing.app ./build/Ex64FlowFieldFollowing.app
rm -r Chapter06_AutonomousAgents/Ex64FlowFieldFollowing/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex65PathFollowing/xcode/Ex65PathFollowing.xcodeproj -target Ex65PathFollowing -configuration Release $@
mv Chapter06_AutonomousAgents/Ex65PathFollowing/xcode/build/Release/Ex65PathFollowing.app ./build/Ex65PathFollowing.app
rm -r Chapter06_AutonomousAgents/Ex65PathFollowing/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex66GroupBehaviors/xcode/Ex66GroupBehaviors.xcodeproj -target Ex66GroupBehaviors -configuration Release $@
mv Chapter06_AutonomousAgents/Ex66GroupBehaviors/xcode/build/Release/Ex66GroupBehaviors.app ./build/Ex66GroupBehaviors.app
rm -r Chapter06_AutonomousAgents/Ex66GroupBehaviors/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex67Flocking/xcode/Ex67Flocking.xcodeproj -target Ex67Flocking -configuration Release $@
mv Chapter06_AutonomousAgents/Ex67Flocking/xcode/build/Release/Ex67Flocking.app ./build/Ex67Flocking.app
rm -r Chapter06_AutonomousAgents/Ex67Flocking/xcode/build*

xcrun xcodebuild -project Chapter06_AutonomousAgents/Ex68OptimizedFlocking/xcode/Ex68OptimizedFlocking.xcodeproj -target Ex68OptimizedFlocking -configuration Release $@
mv Chapter06_AutonomousAgents/Ex68OptimizedFlocking/xcode/build/Release/Ex68OptimizedFlocking.app ./build/Ex68OptimizedFlocking.app
rm -r Chapter06_AutonomousAgents/Ex68OptimizedFlocking/xcode/build*



xcrun xcodebuild -project Chapter07_CellularAutomata/Ex71ElementaryCellularAutomata/xcode/Ex71ElementaryCellularAutomata.xcodeproj -target Ex71ElementaryCellularAutomata -configuration Release $@
mv Chapter07_CellularAutomata/Ex71ElementaryCellularAutomata/xcode/build/Release/Ex71ElementaryCellularAutomata.app ./build/Ex71ElementaryCellularAutomata.app
rm -r Chapter07_CellularAutomata/Ex71ElementaryCellularAutomata/xcode/build*

xcrun xcodebuild -project Chapter07_CellularAutomata/Ex72GameOfLife/xcode/Ex72GameOfLife.xcodeproj -target Ex72GameOfLife -configuration Release $@
mv Chapter07_CellularAutomata/Ex72GameOfLife/xcode/build/Release/Ex72GameOfLife.app ./build/Ex72GameOfLife.app
rm -r Chapter07_CellularAutomata/Ex72GameOfLife/xcode/build*



xcrun xcodebuild -project Chapter08_Fractals/Ex81RecursiveCircles/xcode/Ex81RecursiveCircles.xcodeproj -target Ex81RecursiveCircles -configuration Release $@
mv Chapter08_Fractals/Ex81RecursiveCircles/xcode/build/Release/Ex81RecursiveCircles.app ./build/Ex81RecursiveCircles.app
rm -r Chapter08_Fractals/Ex81RecursiveCircles/xcode/build*

xcrun xcodebuild -project Chapter08_Fractals/Ex82CantorLines/xcode/Ex82CantorLines.xcodeproj -target Ex82CantorLines -configuration Release $@
mv Chapter08_Fractals/Ex82CantorLines/xcode/build/Release/Ex82CantorLines.app ./build/Ex82CantorLines.app
rm -r Chapter08_Fractals/Ex82CantorLines/xcode/build*

xcrun xcodebuild -project Chapter08_Fractals/Ex83KochLinesSnowflake/xcode/Ex83KochLinesSnowflake.xcodeproj -target Ex83KochLinesSnowflake -configuration Release $@
mv Chapter08_Fractals/Ex83KochLinesSnowflake/xcode/build/Release/Ex83KochLinesSnowflake.app ./build/Ex83KochLinesSnowflake.app
rm -r Chapter08_Fractals/Ex83KochLinesSnowflake/xcode/build*

xcrun xcodebuild -project Chapter08_Fractals/Ex84Tree/xcode/Ex84Tree.xcodeproj -target Ex84Tree -configuration Release $@
mv Chapter08_Fractals/Ex84Tree/xcode/build/Release/Ex84Tree.app ./build/Ex84Tree.app
rm -r Chapter08_Fractals/Ex84Tree/xcode/build*

xcrun xcodebuild -project Chapter08_Fractals/Ex85StochasticTree/xcode/Ex85StochasticTree.xcodeproj -target Ex85StochasticTree -configuration Release $@
mv Chapter08_Fractals/Ex85StochasticTree/xcode/build/Release/Ex85StochasticTree.app ./build/Ex85StochasticTree.app
rm -r Chapter08_Fractals/Ex85StochasticTree/xcode/build*

xcrun xcodebuild -project Chapter08_Fractals/Ex86LSystem/xcode/Ex86LSystem.xcodeproj -target Ex86LSystem -configuration Release $@
mv Chapter08_Fractals/Ex86LSystem/xcode/build/Release/Ex86LSystem.app ./build/Ex86LSystem.app
rm -r Chapter08_Fractals/Ex86LSystem/xcode/build*



xcrun xcodebuild -project Chapter09_TheEvolutionOfCode/Ex91Shakespeare/xcode/Ex91Shakespeare.xcodeproj -target Ex91Shakespeare -configuration Release $@
mv Chapter09_TheEvolutionOfCode/Ex91Shakespeare/xcode/build/Release/Ex91Shakespeare.app ./build/Ex91Shakespeare.app
rm -r Chapter09_TheEvolutionOfCode/Ex91Shakespeare/xcode/build*

xcrun xcodebuild -project Chapter09_TheEvolutionOfCode/Ex92SimpleSmartRockets/xcode/Ex92SimpleSmartRockets.xcodeproj -target Ex92SimpleSmartRockets -configuration Release $@
mv Chapter09_TheEvolutionOfCode/Ex92SimpleSmartRockets/xcode/build/Release/Ex92SimpleSmartRockets.app ./build/Ex92SimpleSmartRockets.app
rm -r Chapter09_TheEvolutionOfCode/Ex92SimpleSmartRockets/xcode/build*

xcrun xcodebuild -project Chapter09_TheEvolutionOfCode/Ex93SmartRockets/xcode/Ex93SmartRockets.xcodeproj -target Ex93SmartRockets -configuration Release $@
mv Chapter09_TheEvolutionOfCode/Ex93SmartRockets/xcode/build/Release/Ex93SmartRockets.app ./build/Ex93SmartRockets.app
rm -r Chapter09_TheEvolutionOfCode/Ex93SmartRockets/xcode/build*

xcrun xcodebuild -project Chapter09_TheEvolutionOfCode/Ex94FacesSelection/xcode/Ex94FacesSelection.xcodeproj -target Ex94FacesSelection -configuration Release $@
mv Chapter09_TheEvolutionOfCode/Ex94FacesSelection/xcode/build/Release/Ex94FacesSelection.app ./build/Ex94FacesSelection.app
rm -r Chapter09_TheEvolutionOfCode/Ex94FacesSelection/xcode/build*

xcrun xcodebuild -project Chapter09_TheEvolutionOfCode/Ex95EvolvingEcosystem/xcode/Ex95EvolvingEcosystem.xcodeproj -target Ex95EvolvingEcosystem -configuration Release $@
mv Chapter09_TheEvolutionOfCode/Ex95EvolvingEcosystem/xcode/build/Release/Ex95EvolvingEcosystem.app ./build/Ex95EvolvingEcosystem.app
rm -r Chapter09_TheEvolutionOfCode/Ex95EvolvingEcosystem/xcode/build*



xcrun xcodebuild -project Chapter10_NeuralNetworks/Ex101SimplePerceptron/xcode/Ex101SimplePerceptron.xcodeproj -target Ex101SimplePerceptron -configuration Release $@
mv Chapter10_NeuralNetworks/Ex101SimplePerceptron/xcode/build/Release/Ex101SimplePerceptron.app ./build/Ex101SimplePerceptron.app
rm -r Chapter10_NeuralNetworks/Ex101SimplePerceptron/xcode/build*

xcrun xcodebuild -project Chapter10_NeuralNetworks/Ex102SeekingNeural/xcode/Ex102SeekingNeural.xcodeproj -target Ex102SeekingNeural -configuration Release $@
mv Chapter10_NeuralNetworks/Ex102SeekingNeural/xcode/build/Release/Ex102SeekingNeural.app ./build/Ex102SeekingNeural.app
rm -r Chapter10_NeuralNetworks/Ex102SeekingNeural/xcode/build*

xcrun xcodebuild -project Chapter10_NeuralNetworks/Ex103Network/xcode/Ex103Network.xcodeproj -target Ex103Network -configuration Release $@
mv Chapter10_NeuralNetworks/Ex103Network/xcode/build/Release/Ex103Network.app ./build/Ex103Network.app
rm -r Chapter10_NeuralNetworks/Ex103Network/xcode/build*

