#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <physics/BallisticState.hpp>
	
BallisticState ds_dt(const BallisticState& state);
StaticVec<double> drag_force_air(StaticVec<double> v, double area, double Cd, double density);
BallisticState release_bolt(double mass, double angle_radians, double force, double draw, double area, double coefficient_drag, std::function<BallisticState(const BallisticState&)> grad_func);

#endif
