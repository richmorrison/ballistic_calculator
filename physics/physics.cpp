#include <physics/physics.hpp>

BallisticState ds_dt(const BallisticState& input)
{
	double g=9.81;
	
	StaticVec<double> drag_force = drag_force_air(input.velocity, input.area, input.cd, input.rho);
	StaticVec<double> drag_deceleration = drag_force*(1/input.mass);
	StaticVec <double> acceleration{drag_deceleration[0], drag_deceleration[1] - g, drag_deceleration[2]};
	
	return BallisticState(
		1,
		0,
		input.velocity,
		acceleration,
		0,
		0,
		0,
		input.get_grad_func()
	);
}

StaticVec<double> drag_force_air(StaticVec<double> v, double area, double Cd, double density)
{
	double force = Cd*density*v.magnitude()*v.magnitude()*area/2;
	return v.normalise()*(-1*force);
}

BallisticState release_bolt(double mass, double angle_radians, double force, double draw, double area, double coefficient_drag, std::function<BallisticState(const BallisticState&)> grad_func)
{
	double energy_launch = force*draw/2;
	
	double velocity = sqrt(2*energy_launch/mass);
	double vx = cos(angle_radians)*velocity;
	double vy = sin(angle_radians)*velocity;
	double vz = 0;
	
	double density_air = 1.2;
	
	return BallisticState( 0, mass, {0,0,0}, {vx, vy, vz}, area, coefficient_drag, density_air, grad_func );
}
