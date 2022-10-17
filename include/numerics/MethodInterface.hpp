#ifndef METHODINTERFACE_HPP
#define METHODINTERFACE_HPP

#include <vector>
#include <functional>


template<class type>
class MethodInterface
{
	protected:
		
		std::function<type(const type&)> ds_dp;
	
	public:
		
		MethodInterface(
			std::function<type(const type&)> grad_func
		)
			: ds_dp(grad_func)
		{}
		
		const std::function<type(const type&)> get_grad_func() const
		{
			return ds_dp;
		}
		
		type grad() const
		{
			return ds_dp(*this);
		}
		
		void solve(
			double step,
			std::function<bool(const type&)> halt,
			void (*method)(
				type& data,
				double step,
				std::function<type(const type&)> grad_func
			)
		)
		{
			while(!halt(*static_cast<type*>(this)))
			{
				method(*static_cast<type*>(this), step, ds_dp);
			}
			
			return;
		}
};

#endif
