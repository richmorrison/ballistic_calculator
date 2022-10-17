#ifndef METHODS_HPP
#define METHODS_HPP

template<class type>
void runge_kutta(type& data, double step, std::function<type(const type&)> grad_func)
{
	type k1 = grad_func(data);
	type k2 = grad_func(data+k1*step/2);
	type k3 = grad_func(data+k2*step/2);
	type k4 = grad_func(data+k3*step);
	
	data = data + (k1 +k2*2 + k3*2 + k4)*step/6;
	
	return;
}

#endif
