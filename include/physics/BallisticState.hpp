#ifndef BALLISTICSTATE_HPP
#define BALLISTICSTATE_HPP

#include <numerics/MethodInterface.hpp>
#include <numerics/StaticVec.hpp>

class BallisticState : public MethodInterface<BallisticState>
{
	public:
	
		double        time;
		double        mass; // Projectile mass
		StaticVec<double> position; // Projectile position
		StaticVec<double> velocity; // Projectile velocity
		double        area; // Reference area for drag
		double          cd; // Drag coefficient
		double         rho; // Air density
		
		BallisticState(
			double time,
			double mass,
			StaticVec<double> position,
			StaticVec<double> velocity,
			double area,
			double cd,
			double rho,
			std::function<BallisticState(const BallisticState&)> grad_func
		);
		
		BallisticState operator*(double rhs) const;
		BallisticState operator/(double rhs) const;
		BallisticState operator+(const BallisticState& rhs) const;
		
		BallisticState& operator=(BallisticState&& rhs);
};

#endif
