#ifndef STATIC_VEC_HPP
#define STATIC_VEC_HPP

#include <initializer_list>
#include <vector>
#include <cmath>

template<class type>
class StaticVec
{
	private:
		std::vector<type> data;
		
		StaticVec(std::vector<type>&& items)
		{
			data = std::move(items);
		}
		
	public:
		
		StaticVec(std::initializer_list<type> items)
			: data{items}
		{}
		
		StaticVec()
		{}
		
		type& operator[](size_t i)
		{
			return data[i];
		}
		
		size_t size() const
		{
			return data.size();
		}
		
		const type& operator[](size_t i) const
		{
			return data[i];
		}
		
		StaticVec operator*(double rhs) const
		{
			std::vector<type> new_data;
			
			for(type val : data)
				new_data.push_back(val*rhs);
			
				return StaticVec(std::move(new_data));
		}
		
		StaticVec operator+(StaticVec<type> rhs) const
		{
			std::vector<type> new_data;
			
			for(int i=0; i<data.size(); i++)
				new_data.push_back(this->data[i]+rhs[i]);
			
				return StaticVec(std::move(new_data));
		}
		
		type magnitude() const
		{
			type ret=0;
			for(auto i : data)
				ret += i*i;
			return sqrt(ret);
		}
		
		StaticVec<type> normalise() const
		{
			return this->operator*(1/this->magnitude());
		}
};

#endif
