import os

chapters = [ "Chapter01_Vectors",
             "Chapter02_Forces",
             "Chapter03_Oscillation",
             "Chapter04_ParticleSystems",
             "Chapter05_PhysicsLibraries",
             "Chapter06_AutonomousAgents",
             "Chapter07_CellularAutomata",
             "Chapter08_Fractals",
             "Chapter09_TheEvolutionOfCode",
             "Chapter10_NeuralNetworks" ]

f = open('build_all_mac.sh','w')
f.write("#!/bin/sh\n\n")

for ch in chapters:
    f.write("\n\n")
    for root, dirs, files in os.walk(ch + "/", topdown=True):
        for d in dirs:
            if d.endswith("xcodeproj"):
                f.write("xcrun xcodebuild -project " + ch + "/" + d[:-10] + "/xcode/" + d + " -target " + d[:-10] + " -configuration Release $@\n")
                f.write("mv " + ch + "/" + d[:-10] + "/xcode/build/Release/" + d[:-10] + ".app" + " ./build/" + d[:-10] + ".app\n")
                f.write("rm -r " + ch + "/" + d[:-10] + "/xcode/build*\n\n")