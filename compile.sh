#!/bin/sh -f

g++ \
	-fpermissive						\
	-O0 -g							\
	-std=c++17						\
	-fconcepts						\
								\
	-Iinclude						\
								\
	main.cpp						\
	physics/BallisticState.cpp				\
	physics/physics.cpp					\
	gui/BallisticsApp.cpp					\
	gui/MainWindow.cpp					\
	gui/elements/plot/LinePlot.cpp				\
	gui/elements/InputPanel.cpp				\
	gui/elements/LabelledTextBox.cpp			\
								\
	-IwxFreeChart/include					\
	-LwxFreeChart/lib					\
	-Wl,-rpath,wxFreeChart/lib				\
					                        \
	-IwxWidgets/include -LwxWidgets/build_gtk/lib		\
	`wxWidgets/build_gtk/wx-config --cxxflags --libs`	\
	-lwxcode_gtk3u_freechart-3.3				\
								\
	-o ballistic_calculator
