#include <physics/BallisticState.hpp>

BallisticState::BallisticState(
	double time,
	double mass,
	StaticVec<double> position,
	StaticVec<double> velocity,
	double area,
	double cd,
	double rho,
	std::function<BallisticState(const BallisticState&)> grad_func
)
	:	MethodInterface<BallisticState>( grad_func )
{
	this->time = time;
	this->mass = mass;
	this->position = position,
	this->velocity = velocity,
	this->area = area;
	this->cd = cd;
	this->rho = rho;
}

BallisticState BallisticState::operator*(double rhs) const
{
	return BallisticState(
		time*rhs,
		mass*rhs,
		position*rhs,
		velocity*rhs,
		area*rhs,
		cd*rhs,
		rho*rhs,
		ds_dp		
	);
}

BallisticState BallisticState::operator/(double rhs) const
{
	return operator*(1/rhs);
}


BallisticState BallisticState::operator+(const BallisticState& rhs) const
{
	return BallisticState(
		time+rhs.time,
		mass+rhs.mass,
		position+rhs.position,
		velocity+rhs.velocity,
		area+rhs.area,
		cd+rhs.cd,
		rho+rhs.rho,
		ds_dp	
	);
}

BallisticState& BallisticState::operator=(BallisticState&& rhs)
{
	time=rhs.time;
	mass=rhs.mass;
	position=rhs.position;
	velocity=rhs.velocity;
	area=rhs.area;
	cd=rhs.cd;
	rho=rhs.rho;
	ds_dp=rhs.ds_dp;
	
	return *this;
}
